import java.util.LinkedList;

public class p211 {
    public class WordDictionary {
        class TrieNode {
            char content;
            boolean isEnd;
            int count;
            public LinkedList<TrieNode> childList;

            /* Constructor */
            public TrieNode(char c) {
                childList = new LinkedList<TrieNode>();
                isEnd = false;
                content = c;
                count = 0;
            }

            public TrieNode subNode(char c) {
                if (childList != null)
                    for (TrieNode eachChild : childList)
                        if (eachChild.content == c)
                            return eachChild;
                return null;
            }
        }

        class Trie {
            private String word_;
            private TrieNode root;

            public Trie() {
                root = new TrieNode(' ');
            }

            public void insert(String word) {
                if (search(word))
                    return;
                TrieNode current = root;
                for (char ch : word.toCharArray()) {
                    TrieNode child = current.subNode(ch);
                    if (child != null)
                        current = child;
                    else {
                        current.childList.add(new TrieNode(ch));
                        current = current.subNode(ch);
                    }
                    current.count++;
                }
                current.isEnd = true;
            }

            public boolean search(String word) {
                word_ = word;
                return search(root, 0);
            }

            private boolean search(TrieNode root, int pos) {
                TrieNode current = root;
                boolean encounterDot = false;
                for (int i = pos; i < word_.length(); ++i) {
                    char ch = word_.charAt(i);
                    if (ch == '.') {
                        encounterDot = true;
                        boolean found = false;
                        if (current.childList.isEmpty()) {
                            return false;
                        } else {
                            for (TrieNode next : current.childList) {
                                if (search(next, i + 1)) {
                                    found = true;
                                    break;
                                }
                            }
                        }
                        if (found) {
                            return true;
                        }
                        break;
                    } else {
                        if (current.subNode(ch) == null)
                            return false;
                        else
                            current = current.subNode(ch);
                    }
                }
                if (encounterDot) return false;
                if (current.isEnd) {
                    return true;
                }
                return false;
            }

            public void remove(String word) {
                if (!search(word)) {
                    System.out.println(word + " does not exist in trie\n");
                    return;
                }
                TrieNode current = root;
                for (char ch : word.toCharArray()) {
                    TrieNode child = current.subNode(ch);
                    if (child.count == 1) {
                        current.childList.remove(child);
                        return;
                    } else {
                        child.count--;
                        current = child;
                    }
                }
                current.isEnd = false;
            }
        }

        public WordDictionary() {
            trie = new Trie();
        }

        public void addWord(String word) {
            trie.insert(word);
        }

        public boolean search(String word) {
            return trie.search(word);
        }

        private Trie trie;
    }
}
