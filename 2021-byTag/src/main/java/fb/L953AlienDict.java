package fb;

/**
 * @author lei
 * @date 09/25/2021 5:30 PM
 *
 * essentially a
 */
public class L953AlienDict {
    int[] map = new int[26];

    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < order.length(); ++i) {
            map[order.charAt(i) - 'a'] = i;
        }
        for (int i = 1; i < words.length; ++i) {
            if (bigger(words[i-1], words[i]))
                return false;
        }
        return true;
    }

    public boolean bigger(String a, String b) {
        int m = a.length(), n = b.length();
        for (int i= 0; i < n && i < m; ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                return map[a.charAt(i) - 'a'] >  map[b.charAt(i) - 'a'];
            }
        }
        return m > n;
    }
}
