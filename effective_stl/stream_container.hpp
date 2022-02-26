/// Copyright 2021.
#ifndef STREAM_CONTAINER_HPP_
#define STREAM_CONTAINER_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>

namespace effec_stl {
/// Sends formatted container data to an output stream.
class StreamContainer final {
 public:
  StreamContainer(std::ostream& out = std::cout, const char* sep = ",",
                  const char* term = "\n")
      : _out(out), _sep(sep), _term(term) {}

  template <typename C>
  std::ostream& operator<<(const C& cont) const {
    using type = typename C::value_type;
    std::copy_n(cont.begin(), cont.size() - 1,
                std::ostream_iterator<type>(_out, _sep));
    std::copy(cont.end() - 1, cont.end(),
              std::ostream_iterator<type>(_out, _term));
    return _out;
  }

 private:
  std::ostream& _out;
  const char* _sep;
  const char* _term;
};
}  // namespace effec_stl

#endif  // STREAM_CONTAINER_HPP_
