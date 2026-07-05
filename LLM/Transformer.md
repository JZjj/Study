# Transformer

## Contents

- [Overview](#overview)
- [Key Ideas](#key-ideas)
- [Tokenization & Word Embedding](#tokenization--word-embedding)
- [Positional Encoding](#positional-encoding)
- [Attention](#attention)

## Overview

A Transformer is built from repeated blocks. Each block lets tokens exchange
information and stabilizes the update.

## Key Ideas

### Multi-Head Attention

Each head can learn a different relationship, such as syntax, position,
coreference, or long-range dependency.

### Add & Norm

Add & Norm means residual connection plus layer normalization.

The residual connection adds the block input back to the block output:

```text
combined = input + sublayer_output
```

This helps gradients flow through deep networks and prevents each layer from
having to relearn the original input.

Layer normalization then rescales the representation so training is more
stable:

```text
normalized_output = LayerNorm(combined)
```

### Feedforward Network

The feedforward network is a small MLP applied independently to each token
after attention. Attention mixes information across tokens; the feedforward
network transforms each token's representation.

Usually it expands the hidden dimension, applies a nonlinearity, then projects
back:

```text
hidden -> larger hidden -> hidden
```

This gives the model more capacity to compute useful features after tokens have
shared information.

### Code Example

```python
import torch
import torch.nn as nn


class TransformerBlock(nn.Module):
    def __init__(self, hidden_size, num_heads, ff_size):
        super().__init__()
        self.attn = nn.MultiheadAttention(
            embed_dim=hidden_size,
            num_heads=num_heads,
            batch_first=True,
        )
        self.norm1 = nn.LayerNorm(hidden_size)
        self.norm2 = nn.LayerNorm(hidden_size)
        self.ffn = nn.Sequential(
            nn.Linear(hidden_size, ff_size),
            nn.GELU(),
            nn.Linear(ff_size, hidden_size),
        )

    def forward(self, x):
        # Multi-head attention: tokens read information from other tokens.
        attn_out, _ = self.attn(x, x, x)

        # Add & Norm: residual connection plus layer normalization.
        x = self.norm1(x + attn_out)

        # Feedforward: transform each token independently.
        ff_out = self.ffn(x)

        # Add & Norm again.
        x = self.norm2(x + ff_out)
        return x


batch_size = 2
seq_len = 5
hidden_size = 16

x = torch.randn(batch_size, seq_len, hidden_size)
block = TransformerBlock(hidden_size=16, num_heads=4, ff_size=64)
y = block(x)

print(y.shape)  # torch.Size([2, 5, 16])
```

## Tokenization & Word Embedding

Tokenization splits text into smaller pieces called tokens. A token can be a
word, part of a word, punctuation, or a special symbol.

```text
"Transformer models are powerful"
-> ["Transformer", "models", "are", "powerful"]
```

After tokenization, each token is represented by a discrete token ID.

```text
"Transformer" -> token_id = 31497
```

The token ID is still just an integer. The LLM uses an embedding layer, such as
`nn.Embedding`, to map that ID to a learned dense vector.

```text
nn.Embedding(token_id) -> [0.12, -0.08, 0.44, ...]
```

In simple terms:

```text
tokenization = text -> tokens
tokenizer vocabulary = tokens -> token IDs
embedding layer = token IDs -> vectors
```

PyTorch example:

```python
import torch
import torch.nn as nn

vocab_size = 50000
hidden_size = 768

embedding = nn.Embedding(vocab_size, hidden_size)

token_ids = torch.tensor([[31497, 4211, 389, 5560]])
token_vectors = embedding(token_ids)

print(token_vectors.shape)  # torch.Size([1, 4, 768])
```

## Positional Encoding

Self-attention does not automatically know word order. If the model only sees
token embeddings, the sequence order is missing.

```text
"cat sat" and "sat cat" would contain the same token vectors
```

### Absolute Positional Encoding

Absolute positional encoding gives each position a position vector.

```text
token_vector = token_embedding + position_vector
```

Position 1, position 2, and position 3 each have their own location signal.

### Sinusoidal Positional Encoding

Sinusoidal positional encoding uses fixed sine and cosine functions to create
position vectors.

The vectors are not learned during training. They are computed from formulas.

### Learnable Positional Embedding

Learnable positional embedding also gives each position a vector, but the
position vectors are learned during training.

```text
position_embedding = nn.Embedding(max_seq_len, hidden_size)
```

This is simple and common, but it may not generalize well beyond the maximum
sequence length seen during training.

### Relative Positional Encoding

Relative positional encoding focuses on distance between tokens, not only their
absolute location.

```text
token A attends to token B based on how far B is from A
```

This helps the model learn patterns like nearby words, previous tokens, or
long-range dependencies.

### Rotary Position Embedding

Rotary position embedding, or RoPE, rotates query and key vectors based on
their positions.

Instead of adding a position vector to the token vector, RoPE injects position
information inside attention.

## Attention

### Attention 与传统 Seq2Seq 的区别

传统 Seq2Seq 通常是 encoder-decoder 结构。Encoder 先把输入序列压缩成
hidden states，decoder 在生成每个输出 token 时，再去关注 encoder 的输出。

```text
encoder input -> encoder hidden states
decoder query -> attend to encoder hidden states
```

Transformer 把 attention 变成核心计算方式，不再依赖 RNN 一步一步处理序列。
Self-attention 可以让同一层里的所有 token 同时互相看见。

### Cross-Attention

Cross-attention means `Q` comes from one sequence, while `K` and `V` come from
another sequence.

它可以跨序列查看源语言的表示，以捕捉源语言哪个位置最相关。

```text
Q = decoder_hidden Wq
K = encoder_hidden Wk
V = encoder_hidden Wv
```

This is common in encoder-decoder models, where the decoder attends to the
encoder output.

### Code Example

```python
import torch
import torch.nn as nn

hidden_size = 16
num_heads = 4

attention = nn.MultiheadAttention(
    embed_dim=hidden_size,
    num_heads=num_heads,
    batch_first=True,
)

# Self-attention: Q, K, V come from the same sequence.
x = torch.randn(2, 5, hidden_size)
self_out, _ = attention(x, x, x)

# Cross-attention: Q comes from decoder states;
# K and V come from encoder states.
decoder_hidden = torch.randn(2, 3, hidden_size)
encoder_hidden = torch.randn(2, 5, hidden_size)
cross_out, _ = attention(decoder_hidden, encoder_hidden, encoder_hidden)

print(self_out.shape)   # torch.Size([2, 5, 16])
print(cross_out.shape)  # torch.Size([2, 3, 16])
```
