# Native Encode 模块

## 概述

这个模块实现了一个简化的编码功能，展示了数据流分析中的难点：**使用源字节作为索引访问编码表**。

## 核心难点

在编码过程中，每个源字节被用作base64编码表的索引：

```cpp
// 数据流：source_byte -> table_index -> base64_table[index]
unsigned char source_byte = input_str[i];
unsigned int table_index = source_byte % 64;  // 源字节作为索引
char encoded_char = base64_table[table_index]; // 间接表访问
```

这种间接的数据流使得静态分析工具很难追踪数据流。

## 实现功能

### encodeWithLeak
- 使用源字节作为索引访问base64编码表
- 将编码结果记录到日志中（模拟泄露）
- 展示了数据流分析的挑战

## 数据流分析挑战

1. **间接索引访问**: 源字节通过模运算转换为索引
2. **表查找**: 通过数组索引访问静态编码表
3. **污点传播**: 污点信息在间接访问中容易丢失

## 测试方法

1. 运行应用
2. 点击 "Test Encode with Leak" 按钮
3. 查看日志输出观察数据流

这个实现为数据流分析研究提供了一个简洁的测试用例。 