#include <version>

// containers
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <span>
#include <stack>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// misc
#include <cassert>
#include <chrono>
#include <compare>
#include <concepts>
#include <expected>
#include <filesystem>
#include <format>
#include <functional>
#include <future>
#include <iterator>
#include <memory>
#include <optional>
#if __has_include(<print>)
#    include <print>
#endif
#include <ranges>
#include <source_location>
#include <stdexcept>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

// thirdparty
#include <fmt/core.h>
#include <range/v3/all.hpp>
#include <tl/optional.hpp>

// my includes
#include "siga/util/bind.hpp"
#include "siga/util/experimental.hpp"
#include "siga/util/flag_set.hpp"
#include "siga/util/functional.hpp"
#include "siga/util/iterator.hpp"
#include "siga/util/meta.hpp"
#include "siga/util/scoped.hpp"
#include "siga/util/shared_from_this_base.hpp"
#include "siga/util/toy.hpp"
#include "siga/util/tuple.hpp"
#include "siga/util/utility.hpp"
