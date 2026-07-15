# On Policy Distillation

## Overview

SFT 蒸馏是 off-policy。Student 学的是 teacher 预先生成好的答案，而不是
student 当前自己生成的数据。训练时 student 模仿 teacher 的固定输出；推理时
student 要基于自己已经生成的 token 继续生成，因此容易出现训练数据和实际生成
状态不一致的问题。

```text
teacher distribution != student distribution
```

Mixed RL 把全领域数据都放进同一个 RL 训练过程中，不同领域之间可能互相牵制。

```text
math data
code data
chat data
reasoning data
-> one mixed RL process
```

这会导致某个领域的优化方向影响其他领域，模型很难同时对所有领域都达到最优。

RL 的采样成本也很高，因为模型需要不断生成样本，再用 reward 进行评估。

```text
sample responses -> score with reward -> update policy
```

同时，RL 的监督信号比较稀疏。很多情况下，模型只在完整输出之后得到一个 reward，
而不是每一步 token 都有明确监督。

标准 in-group 方法通常只有一个 reward。这个 reward 很难同时精细地区分不同
领域、不同能力和不同错误类型。

OPD, or On-Policy Distillation, can alleviate the above problems.

First, the student model performs its own rollout. This means the student
generates responses using its current policy, so training data is closer to the
states the student will actually encounter during inference.

```text
prompt -> student rollout -> student-generated trajectory
```

Second, multiple teachers can provide token-level outputs to constrain the
student. Different teachers may specialize in different domains, so their
signals can help integrate domain knowledge.

```text
student token
-> teacher 1 distribution
-> teacher 2 distribution
-> teacher 3 distribution
```

Because teachers can provide supervision at the token level, OPD gives denser
training signals than a single final reward.

```text
RL: one reward after a full response
OPD: teacher signals across many tokens
```

Third, OPD is usually cheaper than continuing RL on the same target, because it
uses teacher outputs to guide student rollouts instead of relying only on
expensive repeated RL sampling and reward evaluation.
