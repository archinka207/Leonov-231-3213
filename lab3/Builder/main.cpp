#include <iostream>
#include <fstream>
#include "TxtReaderDirector.h"
#include "ArticleBuilder.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file.txt> <output_file.xml>" << std::endl;
        return 1;
    }

    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];

    XmlArticleBuilder builder;
    TxtReaderDirector director;

    if (!director.construct(inputFilename, builder)) {
        std::cerr << "Failed to build the article from " << inputFilename << std::endl;
        return 1;
    }

    std::unique_ptr<Article> article = builder.getArticle();
    
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot open output file " << outputFilename << std::endl;
        return 1;
    }

    outFile << article->toXmlString();
    outFile.close();

    std::cout << "Successfully converted " << inputFilename << " to " << outputFilename << std::endl;

    return 0;
}