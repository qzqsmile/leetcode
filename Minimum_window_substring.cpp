/*
 *����һ��counter��¼t�е���ĸ��
 *���s�г���һ���ͽ�counter��1
 *���Ϊ0����ͳ��end-begin��
 *����Ҫע�⣬begin�տ�ʼ����ָ�������λ�ã�
 *��ͣ��ѭ��ʹ��ָ��տ�ʼ�ķ��ϵ�λ��
 * */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c:t) map[c]++;
        int d = INT_MAX, begin = 0, end = 0, head = 0, counter = t.size();
        
        while(end < s.size())
        {
            if(map[s[end++]]-- > 0) counter--;
            while(counter == 0){
                if(end-begin < d) d = end - (head = begin);
                if(map[s[begin++]]++ == 0) counter++;
            }
        }
        
        return d==INT_MAX ? "":s.substr(head, d);
    }
};