# CrossFlowBench: A Benchmark for Cross-Language Static Analysis on HarmonyOS

## Overview

CrossFlowBench is a comprehensive benchmark suite designed to evaluate cross-language static analysis tools for HarmonyOS applications. It systematically covers representative interaction patterns between ArkTS and native C/C++ code through Node-API, providing a standardized evaluation platform for research in HarmonyOS security analysis.

The benchmark includes 21 test cases spanning:
- Basic cross-language data flows
- Advanced interaction patterns
- Data structure operations and others

## Benchmark List

| ID | Test Case | Description |
|----|-----------|-------------|
| T1 | native_source | Source called in native code |
| T2 | native_leak | Data leakage in native code |
| T3 | native_proxy | Data propagated in native call |
| T4 | native_delegation | Source and sink both called in native |
| T5 | native_call_function_sink | Sink in an ArkTS function called in native |
| T6 | native_call_function_source | Source in an ArkTS function called in native |
| T7 | native_call_function_proxy | Data propagated in ArkTS function called in native |
| T8 | native_call_function_delegation | Source and sink both in ArkTS functions called from native |
| T9 | native_proxy_copy | Data propagated in native calls (copied into buffer) |
| T10 | native_call_function_object | Object method call in native |
| T11 | native_complex_data | Accessing object and leaking data in native |
| T12 | native_set_field | Writing data into field in native |
| T13 | native_array_set | Setting array data in native |
| T14 | native_array_get | Getting array data in native |
| T15 | native_array_clean | Taint reassignment in native (string reallocation) |
| T16 | native_error | Data leakage in error handling in native |
| T17 | native_multiple_interaction | Multiple cross-language call interactions |
| T18 | native_multiple_libraries | Multiple library interactions |
| T19 | native_phi_branch | Conditional branching |
| T20 | native_phi_concat | Data leakage of concatenated values |
| T21 | native_encode | Base64 encoding in native |

## Directory Structure

```
CrossFlowBench/
├── native_source/              # Test cases
├── native_leak/
├── ...         
├── native_encode/              
├── HapFiles/                   # Hap files of test cases
│  ├── native_source/           
│  │  └── entry-default.hap
│  ├── native_leak/
│  ├── ...         
│  └── native_encode/  
└── README.md                   # This documentation     
```

## Evaluation Results

Our evaluation of CrossFlowBench with HarmoBridge shows:

- **81.0% accuracy** in recovering cross-language data flows
- **22/26 flows** correctly detected flows
- Significant improvement over baseline approaches (28.6% accuracy)

## Contributing

We welcome contributions to expand CrossFlowBench with additional test cases and patterns. Please submit issues or pull requests with your proposed additions.

