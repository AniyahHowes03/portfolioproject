package contact;

import java.util.ArrayList;

public class ContactService {

	//list to store contacts
	private ArrayList<Contact> contacts = new ArrayList<>();

	//add a new contact
	public void addContact(Contact contact) {

		// Check for duplicate contact IDs
		for (Contact existingContact : contacts) {

			if (existingContact.getContactId()
					.equals(contact.getContactId())) {

				throw new IllegalArgumentException("Contact ID already exists");
			}
		}

		contacts.add(contact);
	}

	//Delete a contact using contact ID
	public void deleteContact(String contactId) {

		contacts.removeIf(contact ->
			contact.getContactId().equals(contactId));
	}

	//Update first name
	public void updateFirstName(String contactId, String firstName) {

		for (Contact contact : contacts) {

			if (contact.getContactId().equals(contactId)) {

				contact.setFirstName(firstName);
			}
		}
	}

	//Update last name
	public void updateLastName(String contactId, String lastName) {

		for (Contact contact : contacts) {

			if (contact.getContactId().equals(contactId)) {

				contact.setLastName(lastName);
			}
		}
	}

	//update phone number
	public void updatePhone(String contactId, String phone) {

		for (Contact contact : contacts) {

			if (contact.getContactId().equals(contactId)) {

				contact.setPhone(phone);
			}
		}
	}

	//update address
	public void updateAddress(String contactId, String address) {

		for (Contact contact : contacts) {

			if (contact.getContactId().equals(contactId)) {

				contact.setAddress(address);
			}
		}
	}

}