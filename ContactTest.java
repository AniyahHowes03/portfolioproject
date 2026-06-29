package contact;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class ContactTest {

	@Test
	public void testValidContact() {

		//create a valid contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		// Check if values were stored correctly
		assertTrue(contact.getContactId().equals("052303"));
		assertTrue(contact.getFirstName().equals("Aniyah"));
		assertTrue(contact.getLastName().equals("Howes"));
		assertTrue(contact.getPhone().equals("1111234567"));
		assertTrue(contact.getAddress().equals("111 Stellar Street"));
	}

	@Test
	public void testInvalidContactId() {

		//test invalid contact ID
		assertThrows(IllegalArgumentException.class, () -> {

			new Contact(
					null,
					"Aniyah",
					"Howes",
					"1111234567",
					"111 Stellar Street");
		});
	}

	@Test
	public void testInvalidPhone() {

		//test invalid phone number
		assertThrows(IllegalArgumentException.class, () -> {

			new Contact(
					"052303",
					"Aniyah",
					"Howes",
					"111",
					"111 Stellar Street");
		});
	}

	@Test
	public void testNullFirstName() {

		//test null first name
		assertThrows(IllegalArgumentException.class, () -> {

			new Contact(
					"052303",
					null,
					"Howes",
					"1111234567",
					"111 Stellar Street");
		});
	}

	@Test
	public void testNullLastName() {

		//test null last name
		assertThrows(IllegalArgumentException.class, () -> {

			new Contact(
					"052303",
					"Aniyah",
					null,
					"1111234567",
					"111 Stellar Street");
		});
	}
}