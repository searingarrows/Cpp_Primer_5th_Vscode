#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <memory>
#include <map>
class QueryResult;
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
public:
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s,
	    std::shared_ptr<std::set<line_no>> p,
	    std::shared_ptr<std::vector<std::string>> f)
	    : sought(s)
	    , lines(p)
	    , file(f) {}
	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end() { return lines->end(); }
	// std::set<line_no>::const_iterator begin() const { return lines->cbegin(); }
	// std::set<line_no>::const_iterator end() const { return lines->cend(); }
	// std::set<line_no>::const_iterator cbegin() { return lines->cbegin(); }
	// std::set<line_no>::const_iterator cend() { return lines->cend(); }

private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::TextQuery(std::ifstream& is)
    : file(new std::vector<std::string>) {
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines) {
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string& sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);
	}
	else {
		return QueryResult(sought, loc->second, file);
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times" : " time")
	   << std::endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}
#endif