#include <iostream>
#include <map>
#include <queue>
#include <vector>

/*
Họ và tên: Trần Nhật Quang
MSSV: 20224456
*/
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Hàm tính tổng dọc của cây nhị phân
vector<int> verticalSum(TreeNode* root) {
    if (!root) return {}; // Trường hợp cây rỗng

    // Sử dụng map để lưu tổng giá trị theo cột
    map<int, int> columnSum;

    // Hàng đợi để duyệt cây, lưu (node, column)
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0}); // Gốc cây bắt đầu từ cột 0

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        // Cập nhật tổng giá trị cho cột hiện tại
        columnSum[col] += node->val;

        // Thêm con trái vào hàng đợi với cột (col - 1)
        if (node->left) q.push({node->left, col - 1});

        // Thêm con phải vào hàng đợi với cột (col + 1)
        if (node->right) q.push({node->right, col + 1});
    }

    // Tạo danh sách kết quả từ cột nhỏ nhất đến lớn nhất
    vector<int> result;
    for (auto& [col, sum] : columnSum) {
        result.push_back(sum);
    }

    return result;
}

// Hàm hỗ trợ in danh sách kết quả
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Hàm chính để chạy thử nghiệm
int main() {
    /*
        Cây nhị phân ví dụ:
                  1
                 / \
                2   3
               / \   \
              4   5   6
    */

    // Tạo cây nhị phân
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Tính tổng dọc và in kết quả
    vector<int> result = verticalSum(root);
    cout << "Tổng dọc của cây nhị phân là: ";
    printVector(result);

    return 0;
}
