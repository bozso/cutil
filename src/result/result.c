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
