# FinanceToolApp
This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 17.3.3.

## Functionality
The program allows users to access and manage their financial plans through a user-friendly interface. The current core functionality allows for simplistic interaction to perform complex calculations for compounding interest within an account based on user-defined parameters.
The banking interface provides a menu-based interface that guides users through the process of inputting their financial data. The program makes use of two main classes: GrowthCalculator and InputMenu.
The GrowthCalculator class handles the calculation of investment growth with and without monthly deposits. It takes user input and performs the necessary calculations to determine the growth of the investment over time.
The InputMenu class is responsible for displaying the input menu to the user and gathering the necessary financial data. It prompts the user to enter values for initial investment, monthly deposit, interest rate, and duration.
Once the user provides the required financial information, the program calculates the standard growth and growth with monthly deposits using the GrowthCalculator class.
The UserDisplay class is responsible for displaying the calculated results in a table format.

## Use Case
The banking interface program provides users with a convenient way to manage their financial plans and calculate compounding interest.
By entering their financial data through a user-friendly menu, users can quickly obtain the growth of their investments and make informed decisions.
With potential for future enhancements, this program serves as a useful tool for individuals looking to optimize their financial strategies.

## Development server
Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The application will automatically reload if you change any of the source files.

## Code scaffolding
Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Build
Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory.

## Running unit tests
Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

## Running end-to-end tests
Run `ng e2e` to execute the end-to-end tests via a platform of your choice. To use this command, you need to first add a package that implements end-to-end testing capabilities.

## Further help
To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI Overview and Command Reference](https://angular.io/cli) page.