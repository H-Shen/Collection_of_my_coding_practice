func findLUSlength(a string, b string) int {
    if len(a) == len(b) && a == b {
        return -1   
    }
    if len(a) > len(b) {
        return len(a)
    }
    return len(b)
}