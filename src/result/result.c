#include "result/result.h"

bool is_error(Result const res) { return res.status == StatusError; }

Option option_some(result_id id) {
    return (Option){
        .tag = OptionSome,
        .id = id,
    };
}

Option option_none(void) {
    return (Option){
        .tag = OptionNone,
        .id = 0,
    };
}

ResultPtr error_ptr(result_id id) {
    return (ResultPtr){
        .status = StatusError,
        .ptr_or_id = (PtrOrID){.id = id},
    };
}

ResultPtr ok_ptr(void* ptr) {
    return (ResultPtr){
        .status = StatusOk,
        .ptr_or_id = (PtrOrID){.ptr = ptr},
    };
}
