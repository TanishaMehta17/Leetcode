class Solution {
private:
    int findMinSteps(int currentLength, int clipboardLength, int targetLength) {
        if (currentLength == targetLength)
            return 0;
        if (currentLength > targetLength)
            return 1e5;

        int copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength, targetLength);
        int pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength, targetLength);

        return std::min(copyAndPaste, pasteOnly);
    }

public:
    int minSteps(int targetLength) {
        if (targetLength == 1)
            return 0;

        return 1 + findMinSteps(1, 1, targetLength);
    }
};
