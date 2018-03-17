

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public String randomScheme() {
     // TODO: Implement
   }

   public String randomAuthority() {
     // TODO: Implement
   }

   public String randomPort() {
     // TODO: Implementv
   }

   public String randomPath() {
    // TODO: Implement
   }

   public String randomQuery() {
     // TODO: Implement
   }

   public void randomTestIsValid()
    {
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      for (int x = 0; x < 100,000; x++) {
        assertTrue(randomScheme() + randomAuthority() + randomPort() + randomPath() + randomQuery());
      }
    }

}
