//查找数组中第K大的数字
//实现最大堆与最小堆的建立的使
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Less {
    bool operator()(const T& left, const T& right) const {
        return left < right;
    }
};

template <class T>
struct Greater {
    bool operator()(const T& left, const T& right) const {
        return left > right;
    }
};

template <class T, class Compare = Less<T>>
class Heap {
   public:
    Heap()  //无参的构造函数（系统不会给无参构造函数），开始堆是空的不需要做什么事
    {}
    Heap(T* a, size_t n) {
        _a.reserve(n);  //开空间
        for (size_t i = 0; i < n; ++i) {
            _a.push_back(a[i]);
        }
        //建堆,找最后一个非叶子节点
        for (int i = (_a.size() - 2) / 2; i >= 0;
             --i)  //不用size_t，因为i在这可能等于0，用size_t会死循环
        {
            AdjustDown(i);
        }
    }
    //向下调整
    void AdjustDown(int root) {
        Compare com;
        int parent = root;
        size_t child = parent * 2 + 1;  //默认为左孩子
        while (child < _a.size()) {
            //选出小孩子
            // if (child+1 > _a.size() && _a[child + 1]< _a[child])
            if (child + 1 < _a.size() && com(_a[child + 1], _a[child])) {
                ++child;
            }

            // if (_a[child] < _a[parent])
            if (com(_a[child], _a[parent])) {
                swap(_a[child], _a[parent]);  //交换值
                parent = child;
                child = parent * 2 + 1;
            } else {
                break;
            }
        }
    }
    //向上调整
    void AdjustUp(int child) {
        Compare com;
        int parent = (child - 1) / 2;
        while (parent >= 0) {
            // if (_a[child] < _a[parent])
            if (com(_a[child], _a[parent])) {
                swap(_a[parent], _a[child]);
                child = parent;
                parent = (child - 1) / 2;
            } else {
                break;
            }
        }
    }
    //最后插入
    void Push(const T& x) {
        _a.push_back(x);
        AdjustUp(_a.size() - 1);
    }
    //删除最大数
    void Pop() {
        assert(!_a.empty());
        swap(_a[0], _a[_a.size() - 1]);
        _a.pop_back();
        AdjustDown(0);
    }
    //取顶元素
    T& Top() {
        assert(!_a.empty());
        return _a[0];
    }
    size_t Size() { return _a.size(); }

    bool Empty() { return _a.empty(); }

   private:
    vector<T> _a;
};

template <class T>
T findKthLargest(T nums[], int k, int len) {
    Heap<T, Greater<T>> maxHeap(nums, len);
    T res;
    if (k > len) res = -1;
    while (k) {
        res = maxHeap.Top();
        maxHeap.Pop();
        k--;
    }
    return res;
}

int main() {
    int a[] = {10, 11, 13, 12, 16, 18, 15, 17, 14, 19};
    int len = sizeof(a) / sizeof(a[0]);
    int res = findKthLargest(a, 2, len);
    cout << "The Kth max number is : " << res << endl;
    system("pause");
    return 0;
}
