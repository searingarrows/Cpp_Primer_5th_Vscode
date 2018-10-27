#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);

private:
	OrQuery(const Query& l, const Query& r)
	    : BinaryQuery(l, r, "|") {}
	QueryResult eval(const TextQuery&) const override;
};
inline Query operator|(const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& t) const {
	auto right = rhs.eval(t), left = lhs.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(),left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

#endif