bool is_palindromic(std::string s)
{
    std::size_t i = 0;
    std::size_t j = s.length() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}