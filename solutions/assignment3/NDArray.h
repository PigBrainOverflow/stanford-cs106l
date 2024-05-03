#ifndef NDARRAY_H
#define NDARRAY_H

#include <vector>
#include <memory>
#include <iostream>

template <typename DTYPE>
class NDArray {
    public:
        using dtype = DTYPE;    // data type
        using stype = int;  // shape & strides type

        // *************
        // basic methods
        // *************

        // construct by shape and default value
        NDArray(std::initializer_list<stype> shape, dtype value=0)
        : _shape(shape), _strides(shape.size()), _offset{0} {
            _strides[shape.size() - 1] = 1;
            for (stype i = shape.size() - 2; i >= 0; i--) {
                _strides[i] = _strides[i + 1] * _shape[i + 1];
            }
            _entry = std::make_shared<std::vector<dtype>>(_strides[0] * _shape[0], value);
        }

        // construct by another ndarray with new shape, strides and offset
        // share data entry
        NDArray(const NDArray<dtype>& other, std::initializer_list<stype> shape, std::initializer_list<stype> strides, stype offset)
        : _shape(shape), _strides(strides), _offset{offset}, _entry{other._entry} {}

        // ***************
        // utility methods
        // ***************

        stype size() const {
            stype size = 1;
            for (auto i = 0; i < _shape.size(); i++) {
                size *= _shape[i];
            }
            return size;
        }

        stype dim() const { return _shape.size(); }

        dtype& operator[](std::initializer_list<stype> index) {
            stype offset = 0, j = 0;
            for (auto i : index) {
                offset += i * _strides[j++];
            }
            return (*_entry)[offset + _offset];
        }

        const dtype& operator[](std::initializer_list<stype> index) const {
            return const_cast<NDArray<dtype>&>(*this)[index];
        }

    private:
        std::vector<stype> _shape;
        std::vector<stype> _strides;
        stype _offset;
        std::shared_ptr<std::vector<dtype>> _entry;
};

// no need for .cpp
#endif