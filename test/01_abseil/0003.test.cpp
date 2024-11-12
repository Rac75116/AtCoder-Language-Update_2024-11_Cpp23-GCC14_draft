// The Abseil Flags Library
// ref: https://abseil.io/docs/cpp/guides/flags#the-abseil-flags-library
#include "absl/flags/flag.h"
#include "absl/time/time.h"

ABSL_FLAG(bool, big_menu, true,
          "Include 'advanced' options in the menu listing");
ABSL_FLAG(std::string, output_dir, "foo/bar/baz/", "output file dir");
ABSL_FLAG(std::vector<std::string>, languages,
          std::vector<std::string>({"english", "french", "german"}),
          "comma-separated list of languages to offer in the 'lang' menu");
ABSL_FLAG(absl::Duration, timeout, absl::Seconds(30), "Default RPC deadline");
ABSL_FLAG(std::optional<std::string>, image_file, std::nullopt,
          "Sets the image input from a file.");

#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/marshalling.h"
#include "absl/strings/string_view.h"

struct PortNumber
{
    explicit PortNumber(int p = 0) : port(p) {}

    int port; // Valid range is [0..32767]
};

// Returns a textual flag value corresponding to the PortNumber `p`.
std::string AbslUnparseFlag(PortNumber p)
{
    // Delegate to the usual unparsing for int.
    return absl::UnparseFlag(p.port);
}

// Parses a PortNumber from the command line flag value `text`.
// Returns true and sets `*p` on success; returns false and sets `*error`
// on failure.
bool AbslParseFlag(absl::string_view text, PortNumber *p, std::string *error)
{
    // Convert from text to int using the int-flag parser.
    if (!absl::ParseFlag(text, &p->port, error))
    {
        return false;
    }
    if (p->port < 0 || p->port > 32767)
    {
        *error = "not in range [0,32767]";
        return false;
    }
    return true;
}

ABSL_FLAG(PortNumber, port, PortNumber(0), "What port to listen on");

#include "absl/strings/str_cat.h"
#include "absl/strings/str_split.h"

namespace foo
{
    enum class OutputMode
    {
        kPlainText,
        kHtml
    };

    // AbslParseFlag converts from a string to OutputMode.
    // Must be in same namespace as OutputMode.

    // Parses an OutputMode from the command line flag value `text`. Returns
    // `true` and sets `*mode` on success; returns `false` and sets `*error`
    // on failure.
    bool AbslParseFlag(absl::string_view text,
                       OutputMode *mode,
                       std::string *error)
    {
        if (text == "plaintext")
        {
            *mode = OutputMode::kPlainText;
            return true;
        }
        if (text == "html")
        {
            *mode = OutputMode::kHtml;
            return true;
        }
        *error = "unknown value for enumeration";
        return false;
    }

    // AbslUnparseFlag converts from an OutputMode to a string.
    // Must be in same namespace as OutputMode.

    // Returns a textual flag value corresponding to the OutputMode `mode`.
    std::string AbslUnparseFlag(OutputMode mode)
    {
        switch (mode)
        {
        case OutputMode::kPlainText:
            return "plaintext";
        case OutputMode::kHtml:
            return "html";
        default:
            return absl::StrCat(mode);
        }
    }
} // namespace foo

namespace my_flag_namespace
{

    struct MyFlagType
    {
        std::pair<int, std::string> my_flag_data;
    };

    bool AbslParseFlag(absl::string_view text, MyFlagType *flag,
                       std::string *err);

    std::string AbslUnparseFlag(const MyFlagType &);

    // Within the implementation, `AbslParseFlag()` will, in turn invoke
    // `absl::ParseFlag()` on its constituent `int` and `std::string` types
    // (which have built-in Abseil flag support.

    bool AbslParseFlag(absl::string_view text, MyFlagType *flag,
                       std::string *err)
    {
        std::pair<absl::string_view, absl::string_view> tokens =
            absl::StrSplit(text, ',');
        if (!absl::ParseFlag(tokens.first, &flag->my_flag_data.first, err))
            return false;
        if (!absl::ParseFlag(tokens.second, &flag->my_flag_data.second, err))
            return false;
        return true;
    }

    // Similarly, for unparsing, we can simply invoke `absl::UnparseFlag()` on
    // the constituent types.
    std::string AbslUnparseFlag(const MyFlagType &flag)
    {
        return absl::StrCat(absl::UnparseFlag(flag.my_flag_data.first),
                            ",",
                            absl::UnparseFlag(flag.my_flag_data.second));
    }
} // my_flag_namespace

int main()
{
    // Read the flag
    absl::Duration d = absl::GetFlag(FLAGS_timeout);

    // Modify the flag
    absl::SetFlag(&FLAGS_timeout, d + absl::Seconds(10));
}
