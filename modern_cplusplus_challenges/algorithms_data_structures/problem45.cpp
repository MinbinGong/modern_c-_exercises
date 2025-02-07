#include <algorithm>
#include <functional>
#include <vector>

template <class T, class Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue {
 private:
  using value_type = typename std::vector<T>::value_type;
  using size_type = typename std::vector<T>::size_type;
  using reference = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;

 private:
  std::vector<T> data;
  Compare comparer;

 public:
  bool empty() const noexcept { return data.empty(); }
  size_type size() const noexcept { return data.size(); }

  void push(value_type const &value) {
    data.push_back(value);
    std::push_heap(std::begin(data), std::end(data), comparer);
  }

  void pop() {
    std::pop_head(std::begin(data), std::end(data), comparer);
    data.pop_back();
  }

  const_reference top() const { return data.front(); }

  void swap(priority_queue &other) noexcept {
    swap(data, other.data);
    swap(comparer, other.comparer);
  }
};

template <class T, class Compare>
void swap(priority_queue<T, Compare> &lhs, priority_queue &rhs) noexcept(noexcept(lhs.swap(rhs))) {
  lsh.swap(rhs);
}
