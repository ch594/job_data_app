Simple command line app I made to keep track of the jobs applied to. It's still a work in progress, but has functionality as of now. It keeps track of the state by saving to a CSV file and opening from that. As of right now spaces in the names are not allowed.

Here are the commands.

```
open

Loads the data from the CSV file.
```
---
```
add [company name] [job title]

Adds that job to the database of jobs applied to.
```
---
```
view [company name]

Lists all the jobs applied to by that company.
```
---
```
update [company namy] [field name] [local id] [yes/no]

As of now there's fields for phone screen, interview, and offer. This lets you update those boolean values. Note that local id is the position in a list and can be seen using the view command.
```
---
```
save

Saves the current state of the program to a CSV file.
```