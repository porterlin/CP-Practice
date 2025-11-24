#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

// 使用 pair<key, index> 支持重複 key

// 宣告
ordered_set st;

// 插入
st.insert({key, ++idx}); // idx 為全局變量初始化為 0

// 計算小於 key 的元素個數
st.order_of_key({key, 0}); // order_of_key 會先比較小於 first，相同的話再比較小於 second。 由於插入時 idx 從 1 開始，所以寫 0 就一定不會把當前的 key 算進去