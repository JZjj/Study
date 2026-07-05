# Transformer

## Contents

- [Overview](#overview)
- [Key Ideas](#key-ideas)
- [Tokenization & Word Embedding](#tokenization--word-embedding)

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

Word embedding turns each token into a vector of numbers so the model can work
with it.

```text
"Transformer" -> [0.12, -0.08, 0.44, ...]
```

In simple terms:

```text
tokenization = text -> tokens
embedding = tokens -> vectors
```
