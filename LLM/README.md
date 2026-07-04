# LLM Study Notes

This folder collects notes on large language models, efficient training, model architecture, evaluation, and deployment.

## Study Map

```mermaid
flowchart TD
    A[LLM Study] --> B[Architecture]
    A --> C[Training]
    A --> D[Inference]
    A --> E[Evaluation]
    A --> F[Papers]

    B --> B1[Transformer]
    B --> B2[Attention]
    B --> B3[State Space Models]
    B --> B4[MoE]

    C --> C1[Pretraining]
    C --> C2[Instruction Tuning]
    C --> C3[RLHF / Preference Optimization]
    C --> C4[Fine-tuning]

    D --> D1[KV Cache]
    D --> D2[Quantization]
    D --> D3[Speculative Decoding]
    D --> D4[Serving Systems]

    E --> E1[Benchmarks]
    E --> E2[Robustness]
    E --> E3[Safety]
    E --> E4[Domain Tasks]
```

## Core Concepts

| Topic | Short Note | Status |
|---|---|---|
| Transformer | Self-attention-based sequence model architecture. | To study |
| Exact attention | Standard softmax attention computed without approximation. | To study |
| IO-aware attention | Exact attention implemented to reduce GPU memory movement, such as FlashAttention. | To study |
| Fine-tuning | Adapting a pretrained model to a task or domain. | To study |
| Quantization | Reducing numerical precision to save memory and speed inference. | To study |

## Paper Notes

Use this format for each paper:

```text
### Paper Title

- Problem:
- Main idea:
- Method:
- Key result:
- Limitation:
- Why it matters:
```

## Implementation Notes

```text
Date:
Model:
Dataset:
Goal:
Command / code:
Result:
Problem:
Next step:
```

## Questions To Revisit

- What is the difference between exact attention, sparse attention, and linear attention?
- When is fine-tuning better than retrieval-augmented generation?
- Which acceleration methods preserve model quality best?

