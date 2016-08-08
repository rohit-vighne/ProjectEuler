#include "Hands.h"

#include <cstdlib>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>

void Hand::getValues(int& val, int& subval)
{
	std::sort(std::begin(cards), std::end(cards));

	subval = std::rbegin(cards)->val;

	Card prev { cards[0].val - 1, cards[0].suit };

	std::multimap<int, int> runs;
	int runLen = 1;
	int maxRunLen = 1;

	bool straight = true;
	bool flush = true;

	for (std::size_t i = 0; i < nCards; ++i)
	{
		Card card = cards[i];

		bool sameAsPrev = card.val == prev.val;
		if (sameAsPrev)
		{
			++runLen;
		}

		if (runLen > 1 && (!sameAsPrev || i == nCards - 1))
		{
			runs.emplace(runLen, prev.val);

			if (runLen > maxRunLen)
				maxRunLen = runLen;

			runLen = 1;
		}

		if (card.val != prev.val + 1)
		{
			straight = false;
		}

		if (card.suit != prev.suit)
		{
			flush = false;
		}

		prev = card;
	}

	if (straight && flush)
	{
		if (cards[0].val == 10)
		{
			val = RoyalFlush;
		}
		else
		{
			val = StraightFlush;
		}
	}
	else if (maxRunLen == 4)
	{
		val = FourOfAKind;
		subval = runs.find(4)->second;
	}
	else if (maxRunLen == 3 && runs.find(2) != runs.end())
	{
		val = FullHouse;
		subval = runs.find(3)->second;
	}
	else if (flush)
	{
		val = Flush;
	}
	else if (straight)
	{
		val = Straight;
	}
	else if (maxRunLen == 3)
	{
		val = ThreeOfAKind;
		subval = runs.find(3)->second;
	}
	else if (maxRunLen == 2)
	{
		if (runs.count(2) == 2)
		{
			val = TwoPairs;
		}
		else
		{
			val = OnePair;
		}

		subval = runs.find(2)->second;
	}
	else
	{
		val = HighCard;
	}
}

int main()
{
	int count = 0;
	for (std::size_t i = 0; i < nHands; i += 2)
	{
		Hand& player1 = hands[i];
		Hand& player2 = hands[i + 1];

		int p1_val, p1_subval;
		int p2_val, p2_subval;

		player1.getValues(p1_val, p1_subval);
		player2.getValues(p2_val, p2_subval);

		if (p1_val > p2_val)
		{
			++count;
		}
		else if (p1_val == p2_val)
		{
			if (p1_subval > p2_subval)
			{
				++count;
			}
			else if (p1_subval == p2_subval)
			{
				for (std::size_t c = Hand::nCards; c-- > 0; )
				{
					int p1Highest = player1.cards[c].val;
					int p2Highest = player2.cards[c].val;
					if (p1Highest != p2Highest)
					{
						if (p1Highest > p2Highest)
						{
							++count;
						}
						break;
					}
				}
			}
		}
	}

	std::cout << "Player 1 wins " << count << '/' << nHands / 2 << " hands" << std::endl;
	system("pause");
}