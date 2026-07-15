#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    std::ifstream in(argv[1], std::ios::binary);
    if (!in) {
        std::fprintf(stderr, "Error: cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    std::ofstream out(argv[2], std::ios::binary);
    if (!out) {
        std::fprintf(stderr, "Error: cannot open output file '%s'\n", argv[2]);
        return 1;
    }

    static char inBuf[1 << 16];
    static char outBuf[1 << 16];
    in.rdbuf()->pubsetbuf(inBuf, sizeof(inBuf));
    out.rdbuf()->pubsetbuf(outBuf, sizeof(outBuf));

    std::string line;
    line.reserve(256); // grows only if a line is longer; reused every iteration

    while (std::getline(in, line)) {
        
        bool hasCR = !line.empty() && line.back() == '\r';
        if (hasCR) line.pop_back();

        std::reverse(line.begin(), line.end());

        out << line;
        if (hasCR) out << '\r';
        out << '\n';
    }

    return 0;
}
