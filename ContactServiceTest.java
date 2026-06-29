package contact;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class ContactServiceTest {

	@Test
	public void testAddContact() {

		//create contact service
		ContactService service = new ContactService();

		//create a contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		//add contact to service
		service.addContact(contact);

		assertTrue(true);
	}

	@Test
	public void testDeleteContact() {

		//create contact service
		ContactService service = new ContactService();

		//create and add contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		service.addContact(contact);

		//delete contact
		service.deleteContact("052303");

		assertTrue(true);
	}

	@Test
	public void testUpdateFirstName() {

		//create contact service
		ContactService service = new ContactService();

		//create and add contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		service.addContact(contact);

		//update first name
		service.updateFirstName("052303", "Niyah");

		assertEquals("Niyah", contact.getFirstName());
	}

	@Test
	public void testUpdateLastName() {

		//create contact service
		ContactService service = new ContactService();

		//create and add contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		service.addContact(contact);

		//update last name
		service.updateLastName("052303", "Smith");

		assertEquals("Smith", contact.getLastName());
	}

	@Test
	public void testUpdatePhone() {

		//create contact service
		ContactService service = new ContactService();

		//create and add contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		service.addContact(contact);

		//update phone number
		service.updatePhone("052303", "5021234567");

		assertEquals("5021234567", contact.getPhone());
	}

	@Test
	public void testUpdateAddress() {

		//create contact service
		ContactService service = new ContactService();

		//create and add contact
		Contact contact = new Contact(
				"052303",
				"Aniyah",
				"Howes",
				"1111234567",
				"111 Stellar Street");

		service.addContact(contact);

		//update address
		service.updateAddress("052303", "206 Pheasant Street");

		assertEquals(" 206 Pheasant Street", contact.getAddress());
	}
}