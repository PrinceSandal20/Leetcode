class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string>m;
    hash<string>h_func;
    string encode(string longUrl) {
        string code="http://tinyurl.com/"+to_string(h_func(longUrl));
        m[code]=longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));