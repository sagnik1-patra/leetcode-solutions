class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;
        
        while (index < words.size()) {
            int totalChars = words[index].length();
            int last = index + 1;
            
            // Greedily determine how many words can fit on this line
            while (last < words.size()) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }
            
            string line;
            int wordCount = last - index;
            
            // If it's the last line or the line has only one word, left-justify
            if (last == words.size() || wordCount == 1) {
                for (int i = index; i < last; ++i) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Distribute spaces evenly
                int totalSpaces = maxWidth - totalChars + (wordCount - 1);
                int spacePerGap = totalSpaces / (wordCount - 1);
                int extraSpaces = totalSpaces % (wordCount - 1);
                
                for (int i = index; i < last; ++i) {
                    line += words[i];
                    if (i < last - 1) {
                        line += string(spacePerGap + (extraSpaces-- > 0 ? 1 : 0), ' ');
                    }
                }
            }
            
            result.push_back(line);
            index = last;
        }
        
        return result;
    }
};
