#ifndef CPPUTIL_RESULT_RESULT_HPP
#define CPPUTIL_RESULT_RESULT_HPP

#include <cstdint>
#include <exception>

namespace cpputil {

enum class Status {
    Ok,
    Error,
};

class Result {

  public:
    using id = std::uint64_t;

    bool is_error(void) noexcept;
    id unwrap(void);

  private:
    Status status;
    id id_;
};

class UnhandledError : public std::exception {
    Result::id id_;

  public:
    explicit UnhandledError(Result::id) noexcept;
    const char* what() const throw() override;
    virtual ~UnhandledError() override = default;
};

} // namespace cpputil

#endif
