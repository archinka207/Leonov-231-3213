#include "Article.h"
#include <sstream>

std::string Article::toXmlString() const {
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    ss << "<article>\n";
    ss << "    <title>" << title << "</title>\n";
    ss << "    <authors>\n";
    for (const auto& author : authors) {
        ss << "        <author>" << author << "</author>\n";
    }
    ss << "    </authors>\n";
    ss << "    <body>\n" << body << "\n    </body>\n";
    ss << "    <hash>" << fileHash << "</hash>\n";
    ss << "</article>";
    return ss.str();
}