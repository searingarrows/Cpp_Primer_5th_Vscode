#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include <algorithm>
#include <iterator>
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);

private:
	AndQuery(const Query& l, const Query& r)
	    : BinaryQuery(l, r, "&") {}
	QueryResult eval(const TextQuery&) const override;
};
inline Query operator&(const Query& lhs, const Query& rhs){
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery& t) const {
	auto right = rhs.eval(t), left = lhs.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	std::set_intersection(left.begin(),left.end(),right.begin(), right.end(),std::inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
#endif