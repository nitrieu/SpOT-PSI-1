#pragma once
#include "cryptoTools/Common/Defines.h"
#include "cryptoTools/Common/BitVector.h"
#include "cryptoTools/Common/Matrix.h"
#include <unordered_map>

namespace osuCrypto
{
    class SimpleIndex
    {
    public:

		struct Bin
		{
			std::unordered_map<u64, std::vector<u64>> values; //<IdxAlterBin, index of items which have this alter bin>
			std::vector<u64> lightBins; //index of alternative light Bins
			u64 cnt;
		};


        u64 mNumBalls, mNumBins, mNumDummies, numIters, mMaxBinSize;

        std::vector<Bin> mBins;
        block mHashSeed;
		AES mAesHasher;
        void print(span<block> items) ;
		void init(u64 inputSize, u64 numBins, u64 numDummies, u64 statSecParam = 40);
        void insertItems(span<block> items);
    };

}