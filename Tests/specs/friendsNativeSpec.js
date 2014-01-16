spec(function() {
	var queries = {
		ios: {
			globals: {
				navigationBar: { class: 'UINavigationBar' }
			},
			login: {
				usernameField: { class: 'UITextField', properties: { placeholder: 'Username' } },
				passwordField: { class: 'UITextField', properties: { placeholder: 'Password' } },
				loginButton: { class: 'TKUIButton', "text": 'Login' }
			},
			activities: {
				tableView: { class: 'UITableView' },
				addButton: { class: 'UIButton', index: 1 },
				logoutButton: { class: 'UIButton', properties: { currentTitle: 'Log out'} }
			},
			activity: {
				textView: { class: 'UITextView' },
				postButton: { class: 'UINavigationButton', properties: { 'currentTitle': 'Post' } }
			}
		}
	};

	var stepRepository = {
		'Given Friends is running': {
			'ios': [
				ios.launch('tsfriends://')
			]
		},
		'And is logged in': {
			'ios': [
				// NOTE: Update the following two lines to use an existing everlive account and password
				ios.setText(queries.ios.login.usernameField, "Telerik", false),
				ios.setText(queries.ios.login.passwordField, "telerik", false),
				ios.tap(queries.ios.login.loginButton),
				ios.wait(3000)
			]
		},
		'When add is tapped': {
			'ios': [
				ios.wait(2000),
				ios.tap(queries.ios.activities.addButton)
			]
		},

		'And something on my mind is input': {
			'ios': [
				ios.setText(queries.ios.activity.textView, 'Hello World', true)
			]
		},

		'And post is tapped': {
			'ios': [
				ios.tap(queries.ios.activity.postButton),
				ios.wait(3000)
			]
		},

		'And logout is tapped': {
			'ios': [
				ios.tap(queries.ios.activities.logoutButton)
			]
		},
		'Then the Activities screen should be displayed' : {
			'ios': [
				ios.getPropertyValue(queries.ios.globals.navigationBar, 'topItem.title', function(result) {
					assert(result).equals('Activities');
				})
			]
		},
		'Then the activity should be posted': {
			'ios': [
				ios.wait(2000),
				ios.scrollToRow(queries.ios.activities.tableView, 0, 0),
				ios.getPropertyValue([{ class: 'UITableViewCell', index: 3 }, { class: 'UILabel', index: 2 }], 'text', function(value) {
					assert(value).equals('Hello World');
				})
			]
		},
		'Then the login screen should be displayed': {
			'ios': [
				ios.getPropertyValue(queries.ios.login.loginButton, 'text', function(value) {
					assert(value).equals('Login');
				})
			]
		}
	};

	describe("Native: Verify button automation functions correctly", function() {
		test("Activities screen should display on login", function() {
			step('Given Friends is running');
			step('And is logged in');
			step('Then the Activities screen should be displayed');
		});

		test("Activities should be posted", function() {
			step('Given Friends is running');
			step('And is logged in');
			step('When add is tapped');
			step('And something on my mind is input');
			step('And post is tapped');
			// step('Then the activity should be posted');
		});

		test("Logout returns to login screen", function() {
			step("Given Friends is running");
			step('And is logged in');
			step('And logout is tapped');
			step('Then the login screen should be displayed');
		});
	}, stepRepository);
});
