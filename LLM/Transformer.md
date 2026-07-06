# Transformer

## Contents

- [Overview](#overview)
- [Key Ideas](#key-ideas)
- [Tokenization & Word Embedding](#tokenization--word-embedding)
- [Positional Encoding](#positional-encoding)
- [Attention](#attention)
- [FFN](#ffn)
- [Normalization](#normalization)
- [Encoder & Decoder](#encoder--decoder)
- [Decoding](#decoding)

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

## Normalization

在 Transformer 中，normalization 的作用是通过标准化隐藏层的输出稳定训练过程，
缓解梯度消失或梯度爆炸问题。

常见 normalization 方法包括：

### Batch Normalization

Batch normalization 在 batch 维度上统计均值和方差。因为每个 batch 的数据分布
可能不一样，normalization 可以防止输入分布不断漂移。

```text
normalize over batch
```

如果每层看到的输入分布一直变化，模型训练会变难，收敛速度会变慢，也更容易
出现梯度消失或梯度爆炸问题。

### Layer Normalization

Layer normalization 对每个 token 的 hidden dimension 做标准化。

```text
normalize over hidden dimension
```

Transformer 中最常用的是 LayerNorm，因为它不依赖 batch 统计，更适合变长
序列和自回归模型。

特点：

```text
不依赖 batch
不依赖 batch size
不依赖时间序列长度
对序列模型效果明显
```

由于 LayerNorm 不依赖 batch 大小和时间序列长度，它在循环网络和序列模型中能
稳定激活分布，加快收敛。

如果用在 CNN 上，LayerNorm 可能会损失某些图像的局部特征，因为它会在更大的
特征维度范围内做标准化。

### Instance Normalization

Instance normalization 通常对每个样本、每个通道单独标准化。

```text
normalize each instance independently
```

它更多用于图像风格迁移等视觉任务，在 LLM 中不常用。

### Group Normalization

Group normalization 把 channels 分成若干组，在每组内部做标准化。

```text
normalize within channel groups
```

它不依赖 batch size，常用于视觉模型；在标准 Transformer LLM 中不如
LayerNorm / RMSNorm 常见。

### RMSNorm

RMSNorm 是 Root Mean Square Layer Normalization。它只用均方根缩放，不减去
均值。

```text
RMSNorm: scale by root mean square
LayerNorm: subtract mean and divide by standard deviation
```

RMSNorm 计算更简单，在很多现代 LLM 中很常见。

## Encoder & Decoder

Encoder 用来做表征提取。它把输入序列转换成一组 hidden states，作为输入内容的
表示。

```text
input sequence -> encoder -> encoder hidden states
```

Decoder 用来解码，并逐步生成目标序列。

```text
previous target tokens -> decoder -> next token
```

在 encoder-decoder Transformer 中，decoder 可以访问 encoder 的输出。生成每个
token 时，decoder 会通过 cross-attention 关注输入序列中最相关的部分。

## Decoding

### Temperature Sampling

Temperature sampling controls how random or conservative the next-token
sampling is.

The model first produces logits, then temperature rescales those logits before
softmax.

```text
probabilities = softmax(logits / temperature)
```

When temperature is low, the largest logit becomes more dominant, so the output
is more deterministic.

```text
temperature < 1 -> sharper distribution -> safer / more conservative
```

When temperature is high, the probability distribution becomes flatter, so the
model samples more diverse tokens.

```text
temperature > 1 -> flatter distribution -> more random / creative
```

Code example:

```python
import torch

logits = torch.tensor([2.0, 1.0, 0.1])

def sample_with_temperature(logits, temperature):
    scaled_logits = logits / temperature
    probs = torch.softmax(scaled_logits, dim=-1)
    token_id = torch.multinomial(probs, num_samples=1)
    return token_id, probs


for temperature in [0.5, 1.0, 2.0]:
    token_id, probs = sample_with_temperature(logits, temperature)
    print("temperature:", temperature)
    print("probabilities:", probs)
    print("sampled token:", token_id.item())
```

In simple terms:

```text
low temperature = more confident, less random
high temperature = more diverse, more random
```

Why this happens:

```text
probabilities = softmax(logits / temperature)
```

If temperature is smaller than 1, dividing by temperature makes the logits
larger.

```text
logits = [2.0, 1.0, 0.1]
temperature = 0.5

logits / temperature = [4.0, 2.0, 0.2]
```

The biggest number becomes much bigger than the others, so softmax gives it
more probability. The distribution becomes sharper.

If temperature is larger than 1, dividing by temperature makes the logits
closer together.

```text
logits = [2.0, 1.0, 0.1]
temperature = 2.0

logits / temperature = [1.0, 0.5, 0.05]
```

The numbers become closer, so softmax gives other tokens more chance. The
distribution becomes flatter.

Example probabilities:

```text
temperature = 0.5 -> [0.86, 0.12, 0.02]
temperature = 1.0 -> [0.66, 0.24, 0.10]
temperature = 2.0 -> [0.50, 0.30, 0.20]
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

### 主流 Attention 方法

#### Scaled Dot-Product Attention

Scaled dot-product attention 是 Transformer 里最基础的 attention 计算方式。

```text
Attention(Q, K, V) = softmax(QK^T / sqrt(d_k)) V
```

其中：

```text
QK^T = query 和 key 的相似度分数
sqrt(d_k) = 缩放项，防止分数过大
softmax = 把分数变成权重
V = 被加权读取的信息
```

#### Multi-Head Attention

Multi-head attention 会把 hidden vector 分成多个 head。每个 head 独立做
attention，然后再把结果拼接起来。

```text
head_1, head_2, ..., head_n -> concat -> output projection
```

这样不同 head 可以学习不同关系。

#### Relative Position Encoding

Relative position encoding 不只看 token 的绝对位置，而是看 token 之间的相对
距离。

```text
当前位置 i 和目标位置 j 的距离 = i - j
```

这让模型更容易学习“附近 token 更重要”或“前后距离模式”。

#### Transformer-XL

Transformer-XL 主要解决长文本建模问题。它把上一段文本的 hidden states 缓存
下来，作为下一段文本的 memory。

```text
previous segment memory + current segment -> longer context
```

这样模型可以跨 segment 看到更长的上下文。

#### Code Example

```python
import math
import torch
import torch.nn as nn


def scaled_dot_product_attention(Q, K, V):
    d_k = Q.size(-1)
    scores = Q @ K.transpose(-2, -1) / math.sqrt(d_k)
    weights = torch.softmax(scores, dim=-1)
    output = weights @ V
    return output, weights


batch_size = 2
num_heads = 4
seq_len = 5
head_dim = 8

Q = torch.randn(batch_size, num_heads, seq_len, head_dim)
K = torch.randn(batch_size, num_heads, seq_len, head_dim)
V = torch.randn(batch_size, num_heads, seq_len, head_dim)

output, weights = scaled_dot_product_attention(Q, K, V)

print(output.shape)   # torch.Size([2, 4, 5, 8])
print(weights.shape)  # torch.Size([2, 4, 5, 5])


# PyTorch built-in multi-head attention.
hidden_size = 32
attention = nn.MultiheadAttention(
    embed_dim=hidden_size,
    num_heads=4,
    batch_first=True,
)

x = torch.randn(batch_size, seq_len, hidden_size)
multi_head_output, attention_weights = attention(x, x, x)

print(multi_head_output.shape)  # torch.Size([2, 5, 32])
```

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

### Transformer 的权重共享

在一些 Transformer 变体或特定实现中，会使用权重共享来减少参数量。

常见做法包括：

```text
不同层共享同一组参数
input embedding 和 output projection 共享权重
```

这样可以让模型更小，但也可能降低每一层学习不同表示的灵活性。

Code example:

```python
import torch
import torch.nn as nn

vocab_size = 50000
hidden_size = 768

token_embedding = nn.Embedding(vocab_size, hidden_size)
lm_head = nn.Linear(hidden_size, vocab_size, bias=False)

# Weight sharing / tied embedding:
# input embedding 和 output projection 使用同一组权重。
lm_head.weight = token_embedding.weight

token_ids = torch.tensor([[1, 25, 300, 1024]])
hidden = token_embedding(token_ids)
logits = lm_head(hidden)

print(hidden.shape)  # torch.Size([1, 4, 768])
print(logits.shape)  # torch.Size([1, 4, 50000])
```

#### GQA: Grouped-Query Attention

GQA 是 Grouped-Query Attention。它让多组 query heads 共享较少数量的
key/value heads。

```text
Multi-Head Attention:
many Q heads, many K heads, many V heads

Grouped-Query Attention:
many Q heads, fewer shared K/V heads
```

Example:

```text
8 query heads
2 key/value heads

Q heads 1-4 share K/V head 1
Q heads 5-8 share K/V head 2
```

这样可以减少 KV cache 内存，提高推理速度，同时通常比只用一个共享 K/V head
的 MQA 保留更好的效果。

Summary:

```text
MHA = Multi-Head Attention
many Q heads, many K heads, many V heads

MQA = Multi-Query Attention
many Q heads, one shared K head, one shared V head

GQA = Grouped-Query Attention
many Q heads, fewer shared K/V heads
```

With 8 query heads:

```text
MHA:
8 Q heads, 8 K heads, 8 V heads

MQA:
8 Q heads, 1 K head, 1 V head

GQA:
8 Q heads, 2 K heads, 2 V heads
```

In short:

```text
MHA = best flexibility, largest KV cache
MQA = smallest KV cache, most sharing
GQA = compromise between MHA and MQA
```

## FFN

### Gated Linear Unit

Gated Linear Unit, or GLU, adds a gate to the feedforward network. One branch
creates candidate features, and another branch decides how much of those
features should pass through.

```text
output = candidate_features * gate
```

In Transformer FFN variants, gated FFNs often replace the standard two-layer
MLP because the gate gives the model more control over which features to keep.

Code example:

```python
import torch
import torch.nn as nn
import torch.nn.functional as F


class GLUFFN(nn.Module):
    def __init__(self, hidden_size, ff_size):
        super().__init__()
        self.up = nn.Linear(hidden_size, ff_size)
        self.gate = nn.Linear(hidden_size, ff_size)
        self.down = nn.Linear(ff_size, hidden_size)

    def forward(self, x):
        candidate_features = self.up(x)
        gate_values = torch.sigmoid(self.gate(x))
        gated_features = candidate_features * gate_values
        return self.down(gated_features)


x = torch.randn(2, 5, 16)
ffn = GLUFFN(hidden_size=16, ff_size=64)
y = ffn(x)

print(y.shape)  # torch.Size([2, 5, 16])
```

### 实际应用

#### ReLU vs GeLU vs Swish

不同激活函数在速度和效果上有取舍。

```text
ReLU: 速度最快，但有神经元死亡问题
Swish: 速度次之，表达更平滑
GeLU: 相对较慢，但在 Transformer / LLM 中很常见
```

ReLU 的神经元死亡问题指的是：如果某些神经元长期输出 0，它们可能很难再被
更新回来。

```text
ReLU(x) = max(0, x)
```

当输入长期小于 0 时，输出一直是 0，梯度也可能变得很弱。

#### GLU 或 激活 + GLU

GLU 或激活函数加 GLU 的 FFN，可以增强表示能力，让模型对信息进行更精细的
选择。

```text
普通 FFN: 变换信息
GLU FFN: 变换信息 + 选择哪些信息通过
```

优点：

```text
表示能力更强
信息选择更精细
```

代价：

```text
计算量更大
参数量可能更多
数据规模不大时，可能更容易过拟合
```
