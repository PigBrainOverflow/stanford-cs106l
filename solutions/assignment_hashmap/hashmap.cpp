#include "hashmap.h"

template<typename K, typename M, typename H>
HashMap<K, M, H>::HashMap() : _size(0), _hash_function(H()), _buckets_array(kDefaultBuckets, nullptr) {};

template<typename K, typename M, typename H>
HashMap<K, M, H>::HashMap(size_t bucket_count, const H& hash):
    _size(0), 
    _hash_function(hash), 
    _buckets_array(bucket_count, nullptr) {};

template<typename K, typename M, typename H>
HashMap<K, M, H>::~HashMap() {
    // TODO
    clear();
}

template<typename K, typename M, typename H>
inline size_t HashMap<K, M, H>::size(){
    return _size;
}

template<typename K, typename M, typename H>
inline bool HashMap<K, M, H>::empty(){
    return _size == 0;
}

template<typename K, typename M, typename H>
inline size_t HashMap<K, M, H>::bucket_count() const noexcept {
    return _buckets_array.size();
}

template<typename K, typename M, typename H>
bool HashMap<K, M, H>::contains(const K& key) {
    // TODO: The implementation of contains should be modified
    return find(key) != end();
}

template<typename K, typename M, typename H>
M& HashMap<K, M, H>::at(const K& key) {
    // TODO: The implementation of at should be modified
    auto itr = find(key);
    if (itr == end()) {
        throw std::runtime_error();
    }
    return itr->second;
}

template <typename K, typename M, typename H>
template <typename InputIter>
// InputIter must be a forward iterator with value type (K, M)
HashMap<K, M, H>::HashMap(InputIter begin, InputIter end, size_t bucket_count, const H& hash)
: HashMap(bucket_count, hash) {
    for (; begin != end; ++begin) {
        insert(*begin);
    }
}

template <typename K, typename M, typename H>
HashMap<K, M, H>::HashMap(std::initializer_list<HashMap<K, M, H>::value_type> init, size_t bucket_count, const H& hash)
: HashMap(bucket_count, hash) {
    for (const auto& v : init) {
        insert(v);
    }
}