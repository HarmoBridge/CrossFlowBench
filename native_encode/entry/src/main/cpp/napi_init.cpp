#include "napi/native_api.h"
#include "hilog/log.h"

// Base64编码表
static const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static napi_value NAPI_Global_encodeWithLeak(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
    // 获取输入字符串
    size_t input_length = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &input_length);
    char* input_str = new char[input_length + 1];
    napi_get_value_string_utf8(env, args[0], input_str, input_length + 1, nullptr);
    
    // 使用源字节作为索引访问编码表
    char* encoded_buffer = new char[256];
    size_t encoded_index = 0;
    
    for (size_t i = 0; i < input_length && i < 64; i++) {
        unsigned char source_byte = input_str[i];
        unsigned int table_index = source_byte % 64;  // 源字节作为索引
        encoded_buffer[encoded_index++] = base64_table[table_index];
    }
    encoded_buffer[encoded_index] = '\0';
    
    // 泄露编码结果
    OH_LOG_INFO(LOG_APP, "Encoded sensitive data: %{public}s", encoded_buffer);
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"encodeWithLeak", nullptr, NAPI_Global_encodeWithLeak, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
