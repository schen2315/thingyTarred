#include "Story.h"

#include <iostream>
#include <ostream>

int main() {
  Word hello("Hello");
  Word bye("Bye");
  Word cs240("CStwoforty");
  /*
  {
    //WORKS
    // test Word + Word
    std::cout << (hello + bye) << std::endl;
    // test Word + Sentence
    std::cout << (hello + (bye + cs240)) << std::endl;
    // test Sentence + Word
    std::cout << ((hello + bye) + cs240) << std::endl;
  }
  
  {
    //WORKS
    // test Sentence + Sentence
    Paragraph p((hello + cs240) + (bye + cs240));
    std::cout << p << std::endl;
    // test Sentence + Paragraph
    std::cout << (hello + hello) + p << std::endl;
    // test Paragraph + Sentence
    std::cout << p + (bye + bye) << std::endl;
    // test Paragraph + Paragraph
    std::cout << p + p << std::endl;
  }

  {
    //WORKS
    //Story s("input.txt");
    Story s;
    Paragraph p((hello + cs240) + (bye + cs240));
    // test Paragraph + Story
    std::cout << p + s << std::endl;
    // test Story + Paragraph
    std::cout << s + p << std::endl;
    // test Story + Story
    std::cout << (s + p) + (p + s) << std::endl;
  }
  
  {
    // test postfix ++/--
    std::cout << hello << std::endl;
    hello++;
    std::cout << hello << std::endl;
    hello--;
    std::cout << hello << std::endl;
    Sentence s(hello + cs240);
    s++;
    std::cout << s << std::endl;
    s--;
    std::cout << s << std::endl;
    Paragraph p(s + (bye + cs240));
    p++;
    std::cout << p << std::endl;
    p--;
    std::cout << p << std::endl;
    Story story("input.txt");
    story = story + p + p;
    story++;
    std::cout << story << std::endl;
    story--;
    std::cout << story << std::endl;
  }
  
  {
    // test operator=
    Word word("what");
    word = hello;
    std::cout << word << std::endl;
    Sentence s(bye + cs240);    
    s = (hello + cs240); 
    std::cout << s << std::endl;
    Paragraph p("It was a rainy day. Everyone stayed inside.");
    p = s + (cs240 + Word("rocks"));
    std::cout << p << std::endl;
    Story story("input.txt");
    story = story + p;
    std::cout << story << std::endl;
  }
  */
  {
    // test operator+(int)
    // Word word("testing");
    // std::cout << word + 1231 << std::endl;
    // std::cout << word + 1 << std::endl;
    // Sentence s(hello + cs240);
    // s--;
    // std::cout << s + 1231 << std::endl;
    // std::cout << s + 1 << std::endl;
    // Paragraph p("it was a rainy day. everyone stayed inside.");
    // Paragraph p2("it was a rainy day. everyone stayed inside? Where did everyone go?");
    // Paragraph p3("it was a rainy day. everyone stayed inside?Where did everyone go!");
    // Paragraph p4("it was a rainy day. everyone stayed inside? \nWhere did everyone go!");
    // std::cout << p << std::endl;
    // std::cout << p2 << std::endl;
    // std::cout << p3 << std::endl;
    // std::cout << p4 << std::endl;
    // std::cout << p + 1231 << std::endl;
    // std::cout << p + 1 << std::endl;
    //Story story("story.txt");
    // std::cout << story << std::endl;
    //story--;
    //std::cout << story + 1231 << std::endl;
    //std::cout << story + 1 << std::endl;
  }
  
  {
    // test prefix ++/--
    // Word w1("Like");
    // std::cout << w1 << "->";
    // std::cout << ++w1 << std::endl;
    // Word w2("likE");
    // std::cout << w2 << "->";
    // std::cout << ++w2 << std::endl;
    // Word w3("LikE");
    // std::cout << w3 << "->";
    // std::cout << ++w3 << std::endl;
    // Word w4("lIKe");
    // std::cout << w4 << "->";
    // std::cout << ++w4 << std::endl;
    // Word w5("this");
    // std::cout << w5 << "->";
    // std::cout << ++w5 << std::endl;
    // Word w6("TRASH");
    // std::cout << w6 << "->";
    // std::cout << ++w6 << std::endl;
    // Word w7("omelet");
    // std::cout << w7 << "->";
    // std::cout << ++w7 << std::endl;
    // Word w8("APPLE");
    // std::cout << w8 << "->";
    // std::cout << ++w8 << std::endl;
    // Sentence s1("In autumn apples are incredibly awesome! ha");
    // Sentence s2("In autumn apples are incredibly awesome?! ha");
    // Sentence s3("In autumn apples are incredi.bly awesome! ha");
    // Sentence s4("In autumn apples are incredibly awesome. ha.");
    // std::cout << s1 << endl;
    // std::cout << s2 << endl;
    // std::cout << s3 << endl;
    // std::cout << s4 << endl;
    // std::cout << ++s1 << "->";
    // std::cout << --s1 << std::endl;
    // Sentence s2("Like this.");
    // std::cout << ++s2 << "->";
    // std::cout << --s2 << std::endl;
    // std::cout << ++(s1+s2) << std::endl;
    // Story story("input.txt");
    // std::cout << std::endl << std::endl << ++story + (s1+s2) << std::endl;
    // std::cout << std::endl << std::endl << --(story + (s1+s2)) << std::endl;
  }
  /*
  {
    // test first/rest
    Sentence s1("In autumn apples are incredibly awesome.");
    std::cout << s1.first() << std::endl;
    std::cout << s1.rest() << std::endl;
    Paragraph p1((hello+cs240) + s1);
    std::cout << p1.first() << std::endl;
    std::cout << p1.rest() << std::endl;
    Story story("input.txt");
    std::cout << story.first() << std::endl;
    std::cout << p1 + story.rest() << std::endl;
  }
  */
  {
    // test story.save
    Story story("out.txt");
    // ++story;
    // story--;
    Word good("good");
    Word morning("morning");
    Word night("night");
    std::cout << story << std::endl;
    //Sentence s("This is some test phrase?");
    // Paragraph p("it was a rainy day. everyone stayed inside? \nWhere did everyone go!");
    //ofstream out;
    //out.open("out.txt");
    // good.save(out);
    // out << " ";
    // night.save(out);
    //s.save(out);
    // p.save(out);
    // out.close();
    // Paragraph intro((good + morning) + (hello + cs240));
    // Paragraph outro((good + night) + (bye + cs240));
    // intro++;
    // outro = outro + 1;

    //outro + 1;
    // std::cout << intro << std::endl;
    // std::cout << outro << std::endl;
    // Sentence s("I WILL SOLVE THIS SHIT!");
    // std::cout << s << std::endl;
    // Sentence w("COOL SHIT BRO!");
    // s = s + 1;  
    // std::cout << s << std::endl;
    //story = intro + story + outro;
    //story.save("out.txt");
    // outro.save(out);
    // out.close();

  }
  
  return 0;
}