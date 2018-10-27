#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query.h"

class NotQuery : public Query_base {
	friend Query operator~(const Query&);

private:
	NotQuery(const Query& q)
	    : query(q) {}
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const override;
	Query query;
};
inline Query operator~(const Query& rhs) {
	return std::shared_ptr<Query_base>(new NotQuery(rhs));
}

QueryResult NotQuery::eval(const TextQuery& t) const {
	auto result = query.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>(result.begin(), result.end());
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (std::size_t n = 0; n != sz; ++n) {
		if(beg==end||*beg!=n){
			ret_lines->insert(n);
		}else if(beg!=end){
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

#endif
