import java.util.ArrayList;
import java.util.HashMap;


class SuffixTree {
	SuffixTreeNode root = new SuffixTreeNode();
	SuffixTree (String s) {
		for (int i=0; i<s.length();i++) {
			root.insertString(s, i);
		}
	}

	public ArrayList<Integer> getIndex (String s) {
		System.out.println(s);
		return root.getIndex(s);
	}
}

class SuffixTreeNode {
	HashMap<Character, SuffixTreeNode> children = new HashMap<Character, SuffixTreeNode>();
	ArrayList<Integer> indexes = new ArrayList<Integer>();
	char value;

	SuffixTreeNode(){}
	SuffixTreeNode(char v){this.value = v;}

	public void insertString (String s, int index) {
		indexes.add(index);
		if (s != "" || s.length() > 0) {
			char c = s.charAt(0);
			SuffixTreeNode child = null;
			if (children.containsKey(c)) {
				child = children.get(c);
			} else {
				child = new SuffixTreeNode(c);
			}
			child.insertString(s.substring(1), index);
		}
	}

	public ArrayList<Integer> getIndex (String s) {
		System.out.println(s);
		if (s=="" || s.length() == 0) return indexes;
		SuffixTreeNode child = children.get(s.charAt(0));
		if (child == null) return null;
		return child.getIndex(s.substring(1));
	}
}

public class career_cup_20_8 {
	public static void main (String args[]) {
		String s = "mississipi";
		String[] sList = {"ssi", "si", "miss", "pi", "hi", "eh"};
		SuffixTree suffixTree = new SuffixTree(s);
		for (String str:sList) {
			System.out.println(str);
			ArrayList<Integer> list = suffixTree.getIndex(str);
			if (list != null) {
				System.out.println(str + ":" + list.toString());
			}
		}
			
	}
}