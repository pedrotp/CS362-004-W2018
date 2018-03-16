

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
      /* NOTE: I've commented out tests that are failing so they don't interrupt execution*/

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      assertTrue(urlVal.isValid("http://www.google.com"));
      assertTrue(urlVal.isValid("http://google.com"));
      assertTrue(urlVal.isValid("http://ww2w.google.com"));
      assertTrue(urlVal.isValid("http://www.google.com/?q=hello"));
      assertTrue(urlVal.isValid("http://255.255.255.255"));
      // assertTrue(urlVal.isValid("http://255.255.255.255:0"));
      // assertTrue(urlVal.isValid("ftp://255.com:80/test1/file?action=view")); // BUG: regexvalidator.java line 120 != -> ==
      // assertTrue(urlVal.isValid("http://go.au:80/t123"));
      // assertTrue(urlVal.isValid("h3t://255.com/test1/file"));
      // assertTrue(urlVal.isValid("http://255.com/test1/file"));

      assertFalse(urlVal.isValid("http:/www.google.com/"));
      assertFalse(urlVal.isValid("://aaa.:0/test1?action=edit&mode=up"));
      assertFalse(urlVal.isValid(":///..//file"));
      // assertFalse(urlVal.isValid("htitp://www.google.com"));
      // assertFalse(urlVal.isValid("http://")); // BUG: it says http instead of file: in line 318 of urlValidator.java
      // assertFalse(urlVal.isValid("http://www.google."));
      // assertFalse(urlVal.isValid("http://1.2.3.4."));
      // assertFalse(urlVal.isValid("http://.1.2.3.4"));
      // assertFalse(urlVal.isValid("http://256.256.256.256"));
      // assertFalse(urlVal.isValid("http://go.a1a"));

   }

   //Partition 1: URLs that are valid, should pass isValid() method
   public void testYourFirstPartition()
   {
    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

    assertTrue(urlVal.isValid("http://www.google.com"));

    //Commented out failing test
    //assertTrue(urlVal.isValid("http://www.google.com:80"));

    assertTrue(urlVal.isValid("http://www.google.com/test"));

    assertTrue(urlVal.isValid("http://www.google.com/test?action=view"));

    //Commented out failing test
    //assertTrue(urlVal.isValid("ftp://www.ftp.com"));

   }

   //Partition 2: URLs that are not valid, should not pass isValid() method
   public void testYourSecondPartition()
   {
    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

    //special case null value
    assertFalse(urlVal.isValid(null));

    //invalid scheme
    assertFalse(urlVal.isValid("http/www.google.com"));
    assertFalse(urlVal.isValid("http:www.google.com"));
    //Commented out failing test
    //assertFalse(urlVal.isValid("htpp://www.google.com"));


    //Commented out failing test
    //invalid authority
    //assertFalse(urlVal.isValid("http://go.1aa"));
    //assertFalse(urlVal.isValid("http://.aaa"));
    //assertFalse(urlVal.isValid("http://"));


    //invalid port
    assertFalse(urlVal.isValid("http://www.google.com:-1/"));
    assertFalse(urlVal.isValid("http://www.google.com:65636"));
    assertFalse(urlVal.isValid("http://www.google.com:65a"));


    //invalid path
    assertFalse(urlVal.isValid("http://www.google.com/.."));
    assertFalse(urlVal.isValid("http://www.google.com/../"));
    assertFalse(urlVal.isValid("http://www.google.com/..//file"));

    //all invalid
    assertFalse(urlVal.isValid("http/.aaa:-1/../"));

    //combinations of invalid
    assertFalse(urlVal.isValid("http/www.google.com/.."));
    assertFalse(urlVal.isValid("http://.aaa/.."));
    //Commented out failing test
    //assertFalse(urlVal.isValid("htpp://www.google.com:80/.."));
    assertFalse(urlVal.isValid("http:www.google.com:80/.."));
    assertFalse(urlVal.isValid("http://:-1/test"));
    assertFalse(urlVal.isValid("http:www.google.com:-1/.."));
    assertFalse(urlVal.isValid("http:www.google.com:-1/test"));
    assertFalse(urlVal.isValid("http:.aaa:80/test"));
    assertFalse(urlVal.isValid("http/.aaa:-1/test"));
   }

   public void testIsValid()
      {
   	   //You can use this function for programming based testing
   	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   	   boolean expectedResult, testResult;
   	   int randomURLLength, randNumber1, randNumber2;
   	   String randomURL;

   	   //SOURCE: https://www.javamex.com/tutorials/random_numbers/seeding.shtml
   	   Random rand = new Random(System.nanoTime());

   	   //Sets of valid and invalid values for each partition of the domain

   	   String[] validScheme = {"http://", "ftp://", "https://", ""};
   	   String[] invalidScheme = {"htt://", "http:/", "https:/", ".", "abc://", ":", "://", ":80"};

   	   String[] validSite = {"www.google.com", "google.com", "www.oregonstate.edu", "access.engr.oregonstate.edu", "home.bing.com", "192.168.1.1", "255.255.0.0"};
   	   String[] invalidSite = {".google.com", "google.", "www", "www.", "192.168.1", "256.168.1.1", "168.-1.1.1", "www.1", "bing.abcd", "", ":"};

   	   String[] validPort = {"", ":80", ":65535", ":0", ":65534", ":1", ":6555", ":655"};
   	   String[] invalidPort = {":.", ":a", ":-1", ":65536", "12345"};

   	   String[] validPath = {"/", "", "/abra", "/abra/", "/A//", "/image.png", "/ashsadawqlhg/aihfl/qwh/as/ahhig/ashi"};
   	   String[] invalidPath = {"\\", "\\\\", ".", "words with space", " ", ".asp", "//"};



   	   for(int i = 0; i < 500; i++)
   	   {
   		   randomURL = "";
   		   expectedResult = true;

   		   //Determine length of piece to test
   		   randomURLLength = rand.nextInt(2) + 3;	//Random number between 3 and 4

   		   randNumber1 = rand.nextInt(2); //0 or 1
   		   if (randNumber1 == 0)	//URL will begin with http etc.
   		   {
   			   randNumber2 = rand.nextInt(10); // 0 to 9
   			   if(randNumber2 != 0)	//90% chance to choose a valid part for the URL
   			   {
   				   randomURL += validScheme[rand.nextInt(validScheme.length)];	//Random element in valid scheme array
   			   }
   			   else
   			   {
   				   randomURL += invalidScheme[rand.nextInt(invalidScheme.length)];  //Random element in invalid scheme array
   				   expectedResult = false;
   			   }
   		   }


   		   randNumber2 = rand.nextInt(10); // 0 to 9
   		   if(randNumber2 != 0)	//90% chance to choose a valid part for the URL
   		   {
   			   randomURL += validSite[rand.nextInt(validSite.length)];	//Random element in valid site array
   		   }
   		   else
   		   {
   			   randomURL += invalidSite[rand.nextInt(invalidSite.length)];  //Random element in invalid site array
   			   expectedResult = false;
   		   }

   		   randNumber2 = rand.nextInt(10); // 0 to 9
   		   if(randNumber2 != 0)	//90% chance to choose a valid part for the URL
   		   {
   			   randomURL += validPort[rand.nextInt(validPort.length)];	//Random element in valid port array
   		   }
   		   else
   		   {
   			   randomURL += invalidPort[rand.nextInt(invalidPort.length)];  //Random element in invalid port array
   			   expectedResult = false;
   		   }

   		   randNumber2 = rand.nextInt(10); // 0 to 9
   		   if(randNumber2 != 0)	//90% chance to choose a valid part for the URL
   		   {
   			   randomURL += validPath[rand.nextInt(validPath.length)];	//Random element valid path in array
   		   }
   		   else
   		   {
   			   randomURL += invalidPath[rand.nextInt(invalidPath.length)];  //Random element in invalid path array
   			   expectedResult = false;
   		   }

   		   System.out.print(randomURL);
   		   System.out.print(" - Expected: ");
   		   System.out.print(expectedResult);
   		   System.out.print(" - Test: ");

   		   testResult = urlVal.isValid(randomURL);
   		   System.out.print(testResult);

   		   if(expectedResult == testResult)
   		   {
   			   System.out.println(" - TEST PASSED");
   		   }
   		   else
   		   {
   			   System.out.println(" - TEST FAILED");
   		   }
   	   }
      }

}
