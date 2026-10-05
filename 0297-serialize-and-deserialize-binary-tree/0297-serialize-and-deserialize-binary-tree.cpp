class Codec {
public:

    // ---------------- SERIALIZATION ----------------
    void encode(TreeNode* root, string& s) {

        // NULL node
        if (root == NULL) {
            s += "#,";
            return;
        }

        // Store current node
        s += to_string(root->val) + ",";

        // Store left subtree
        encode(root->left, s);

        // Store right subtree
        encode(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        encode(root, s);

        return s;
    }


    // ---------------- DESERIALIZATION ----------------
    TreeNode* decode(vector<string>& nodes, int& i) {

        // If current token is NULL
        if (nodes[i] == "#") {
            i++;
            return NULL;
        }

        // Create current node
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        // Build left subtree
        root->left = decode(nodes, i);

        // Build right subtree
        root->right = decode(nodes, i);

        return root;
    }


    TreeNode* deserialize(string data) {

        // Convert string into tokens
        vector<string> nodes;

        string temp = "";

        for (char ch : data) {

            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp += ch;
            }
        }

        // Start from first token
        int i = 0;

        return decode(nodes, i);
    }
};