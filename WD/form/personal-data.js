document.querySelector('form').addEventListener('submit', function(e) {
    e.preventDefault();
    const fname = document.getElementById("fname").value;
    const lname = document.getElementById("lname").value;
    const dob = document.getElementById("dob").value;
    const contacts = document.getElementById("contacts").value;
    const email = document.getElementById("e-mail").value;
    const address = document.getElementById("address").value;
    const username = fname + lname;

    if (contacts.length !== 10) {
        alert('Enter valid contact number');
        return; 
    }
    if (username.length < 3) {
        alert('Name cannot be less than 3 letters');
        return; 
    }
    console.log('First Name:', fname);
    console.log('Last Name:', lname);
    console.log('DOB:', dob);
    console.log('Contact No:', contacts);
    console.log('Email:', email);
    console.log('Address:', address);

    console.log('submitted');
    // Clear form fields
    document.getElementById("fname").value = '';
    document.getElementById("lname").value = '';
    document.getElementById("dob").value = '';
    document.getElementById("e-mail").value = '';
    document.getElementById("contacts").value = '';
    document.getElementById("address").value = '';

    document.querySelector('.msg').innerHTML = "Form Submitted";
});