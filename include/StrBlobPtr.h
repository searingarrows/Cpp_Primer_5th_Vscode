#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include "StrBlob.h"

class StrBlobPtr {
public:
	StrBlobPtr():curr(0){};
	StrBlobPtr(StrBlob& a, size_t sz = 0)
	    : wptr(a.data)
	    , curr(sz){};
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& rhs) const { return wptr.lock() != rhs.wptr.lock() || curr != rhs.curr; }

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif