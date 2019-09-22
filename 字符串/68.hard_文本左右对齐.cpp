/*

给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> res_list;
        
        int words_size = words.size();
        int index = 0;
        
        while(index < words_size){
            int current_len = 0;
            vector<string> current_word;
            
            current_word.push_back(words[index]);
            current_len += words[index].size();
            index++;
            
            while(index < words_size && current_len + current_word.size() + words[index].size() <= maxWidth){
                current_word.push_back(words[index]);
                current_len += words[index].size();
                index ++;
            }
            
            string res = "";
            
                
            if(index < words_size){
                
                if(current_word.size() == 1){
                    res += current_word[0];
                    while(current_len < maxWidth){
                        res += " ";
                        current_len++;
                    }
                }else{
                    int normal_space_num = (maxWidth -  current_len)/(current_word.size()-1);
                    int carry = (maxWidth -  current_len)%(current_word.size()-1);
                    int space_num = 0;
                    
                    cout<<normal_space_num << " " << carry<<endl;;
                    
                    for(int i =0;i<current_word.size();++i){
                        res += current_word[i];
                        
                        space_num = normal_space_num;
                        if(carry != 0){
                            space_num ++;
                            carry --;
                        }
                        
                        if(i == current_word.size()-1) space_num = 0;
                        
                        
                        while(space_num != 0){
                            res += " ";
                            space_num--;
                        }
                    }
                }
            }else{
                for(int i =0;i<current_word.size();++i){
                    res += current_word[i];
                    if(i != current_word.size()-1){
                        res += " ";
                        current_len++;
                    }
                }
                while(current_len < maxWidth){
                    res += " ";
                    current_len++;
                }
            }
            
            res_list.push_back(res);
            
        }
        
        return res_list;
        
    }
};