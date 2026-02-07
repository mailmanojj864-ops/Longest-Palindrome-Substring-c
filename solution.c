int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];   // To store last index of each character
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = s[right];

        // If character already seen and inside current window
        if (lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        lastIndex[c] = right;

        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
