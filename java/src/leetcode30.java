import java.util.*;

public class leetcode30 {
    public List<Integer> sol(String s, String[] words) {
        List<Integer> ans = new ArrayList<>();

        int wordLength = words[0].length();
        int totalWords = words.length;
        int substringLength = wordLength * totalWords;

        if (s.length() < substringLength) {
            return ans;
        }

        Map<String, Integer> wordCount = new HashMap<>();

        // count the occurences of each word in the words array
        for (String word : words) {
            wordCount.merge(word, 1, Integer::sum);
        }

        // Sliding the window
        for (int i = 0; i < wordLength; i++) {
            Map<String, Integer> currentWordCount = new HashMap<>();
            int wordsFound = 0;
            int left = i;

            //if the dictionary contains current word
            for (int j = i; j <= s.length() - wordLength; j += wordLength) {
                String currentWord = s.substring(j, j + wordLength);
                if (wordCount.containsKey(currentWord)) {
                    currentWordCount.merge(currentWord, 1, Integer::sum);
                    wordsFound ++;
                    while (currentWordCount.get(currentWord) > wordCount.get(currentWord)) {
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCount.put(leftWord, currentWordCount.get(leftWord) - 1);
                        wordsFound--;
                        left += wordLength;
                    }
                    if (wordsFound == totalWords) {
                        ans.add(left);
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCount.put(leftWord, currentWordCount.get(leftWord) - 1);
                        wordsFound--;
                        left += wordLength;
                    }
                } else {
                    currentWordCount.clear();
                    wordsFound = 0;
                    left = j + wordLength;
                }
            }
        }
        return ans;
    }
}
