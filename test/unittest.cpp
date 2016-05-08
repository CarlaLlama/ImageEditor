#define CATCH_CONFIG_MAIN
#include "unittest.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstdlib>


namespace WLBCAR002{
using namespace std;
TEST_CASE("Testing operator overloads and constructors", "[Imageops]"){
		unsigned char[] bufferA = {16, 2, 97, 40, 121, 16};
		unsigned char[] bufferB = {11, 28, 165, 1, 0, 64};

		unsigned char[] sum = {27, 30, 255, 41, 121, 80};
		unsigned char[] diff = {5, 0, 0, 39, 121, 0};
		unsigned char[] inv = {239, 253, 158, 215, 134, 239};
		unsigned char[] mask = {0, 0, 0, 0, 0, 0};
		unsigned char[] thres = {0, 0, 255, 0, 255, 0};

		Image a = new Image(2, 3, &bufferA);
		Image b = new Image(2, 3, &bufferB);
	SECTION("Construction"){

		REQUIRE(a.getWidth == 2);
		REQUIRE(a.getHeight == 3);
		REQUIRE(b.getWidth == 2);
		REQUIRE(b.getHeight == 3);
		REQUIRE(a = bufferA);
		REQUIRE(b = bufferB);
	}

	SECTION("Addition"){
		Image result = a + b;
		Image s = new Image(2, 3, &sum);
		REQUIRE(result == s);
	}

	SECTION("Subtraction"){
		Image result = a - b;
		Image d = new Image(2, 3, &diff);
		REQUIRE(result == d);
	}

	SECTION("Inversion"){
		Image result = !a;
		REQUIRE(result.getDataPntr()->get()[0] == 239);
		REQUIRE(result.getDataPntr()->get()[4] == 134);

	}

	SECTION("Masking"){
		Image result = a / b;
		REQUIRE(result.getDataPntr()->get()[0] == 5);
		REQUIRE(result.getDataPntr()->get()[5] == 0);
	}

	SECTION("Threshold"){
		int f = 50;
		Image result = a * f;
		REQUIRE(result.getDataPntr()->get()[0] == 0);
		REQUIRE(result.getDataPntr()->get()[4] == 255);
	}
}

TEST_CASE("Scenario testing", "[Imageops]"){
		
		REQUIRE(huff.codeTable.at('i') == "1");
		REQUIRE(huff.codeTable.at('a') == "00");
		REQUIRE(huff.codeTable.at('j') == "01");
}

}