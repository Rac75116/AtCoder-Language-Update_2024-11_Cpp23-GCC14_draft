// all headers
// gmockが使われているヘッダはコメントアウトしています
#include "absl/algorithm/algorithm.h"
#include "absl/algorithm/container.h"
#include <absl/base/attributes.h>
#include <absl/base/call_once.h>
#include <absl/base/casts.h>
#include <absl/base/config.h>
#include <absl/base/const_init.h>
#include <absl/base/dynamic_annotations.h>
#include <absl/base/log_severity.h>
#include <absl/base/macros.h>
#include <absl/base/no_destructor.h>
#include <absl/base/nullability.h>
#include <absl/base/optimization.h>
#include <absl/base/policy_checks.h>
#include <absl/base/port.h>
#include <absl/base/prefetch.h>
#include <absl/base/thread_annotations.h>
#include "absl/cleanup/cleanup.h"
#include <absl/container/btree_map.h>
#include <absl/container/btree_set.h>
#include <absl/container/fixed_array.h>
#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>
#include <absl/container/hash_container_defaults.h>
#include <absl/container/inlined_vector.h>
#include <absl/container/node_hash_map.h>
#include <absl/container/node_hash_set.h>
#include "absl/crc/crc32c.h"
#include <absl/debugging/failure_signal_handler.h>
#include <absl/debugging/leak_check.h>
#include <absl/debugging/stacktrace.h>
#include <absl/debugging/symbolize.h>
#include "absl/flags/commandlineflag.h"
#include "absl/flags/config.h"
#include "absl/flags/declare.h"
#include "absl/flags/flag.h"
#include "absl/flags/marshalling.h"
#include "absl/flags/parse.h"
#include "absl/flags/reflection.h"
#include "absl/flags/usage.h"
#include "absl/flags/usage_config.h"
#include <absl/functional/any_invocable.h>
#include <absl/functional/bind_front.h>
#include <absl/functional/function_ref.h>
#include <absl/functional/overload.h>
#include "absl/hash/hash.h"
// #include "absl/hash/hash_testing.h"
#include <absl/log/absl_check.h>
#include <absl/log/absl_log.h>
#include <absl/log/absl_vlog_is_on.h>
#include <absl/log/check.h>
#include <absl/log/die_if_null.h>
#include <absl/log/flags.h>
#include <absl/log/globals.h>
#include <absl/log/initialize.h>
#include <absl/log/log.h>
#include <absl/log/log_entry.h>
#include <absl/log/log_sink.h>
#include <absl/log/log_sink_registry.h>
#include <absl/log/log_streamer.h>
// #include <absl/log/scoped_mock_log.h>
#include <absl/log/structured.h>
#include <absl/log/vlog_is_on.h>
#include "absl/memory/memory.h"
#include <absl/meta/type_traits.h>
#include "absl/numeric/bits.h"
#include "absl/numeric/int128.h"
#include <absl/random/bernoulli_distribution.h>
#include <absl/random/beta_distribution.h>
#include <absl/random/bit_gen_ref.h>
#include <absl/random/discrete_distribution.h>
#include <absl/random/distributions.h>
#include <absl/random/exponential_distribution.h>
#include <absl/random/gaussian_distribution.h>
#include <absl/random/log_uniform_int_distribution.h>
// #include <absl/random/mock_distributions.h>
// #include <absl/random/mocking_bit_gen.h>
#include <absl/random/poisson_distribution.h>
#include <absl/random/random.h>
#include <absl/random/seed_gen_exception.h>
#include <absl/random/seed_sequences.h>
#include <absl/random/uniform_int_distribution.h>
#include <absl/random/uniform_real_distribution.h>
#include <absl/random/zipf_distribution.h>
#include "absl/status/status.h"
// #include "absl/status/status_matchers.h"
#include "absl/status/status_payload_printer.h"
#include "absl/status/statusor.h"
#include <absl/strings/ascii.h>
#include <absl/strings/charconv.h>
#include <absl/strings/charset.h>
#include <absl/strings/cord.h>
#include <absl/strings/cord_analysis.h>
#include <absl/strings/cord_buffer.h>
#include <absl/strings/cord_test_helpers.h>
// #include <absl/strings/cordz_test_helpers.h>
#include <absl/strings/escaping.h>
#include <absl/strings/has_absl_stringify.h>
#include <absl/strings/has_ostream_operator.h>
#include <absl/strings/match.h>
#include <absl/strings/numbers.h>
#include <absl/strings/str_cat.h>
#include <absl/strings/str_format.h>
#include <absl/strings/str_join.h>
#include <absl/strings/str_replace.h>
#include <absl/strings/str_split.h>
#include <absl/strings/string_view.h>
#include <absl/strings/strip.h>
#include <absl/strings/substitute.h>
#include "absl/synchronization/barrier.h"
#include "absl/synchronization/blocking_counter.h"
#include "absl/synchronization/mutex.h"
#include "absl/synchronization/notification.h"
#include <absl/time/civil_time.h>
#include <absl/time/clock.h>
#include <absl/time/time.h>
#include "absl/types/any.h"
#include "absl/types/bad_any_cast.h"
#include "absl/types/bad_optional_access.h"
#include "absl/types/bad_variant_access.h"
#include "absl/types/compare.h"
#include "absl/types/optional.h"
#include "absl/types/span.h"
#include "absl/types/variant.h"
#include <absl/utility/utility.h>

#include <print>
#include <string>
#include <vector>

int main()
{
    const std::vector<std::string> v = {"foo", "bar", "baz"};
    const auto s = absl::StrJoin(v, "-");

    std::println("{}", s);
}
