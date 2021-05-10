#include "result/option.h"

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
