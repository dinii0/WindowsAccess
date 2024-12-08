# <h2 align=center>*WindowsAccess*</h2>

<p align="center">
   <img src= "https://github.com/dinii0/WindowsAccess/blob/main/WindowsAccess/background.jpg?raw=true">
</p>

This is a simple app that checks if the right user has logged in your PC, even tho they knew your profile password.
Everytime the password is typed, the app will gives user few seconds, for them to create a folder with a specific name in the desktop.
After *X* intervals if the folder with the specific name is not in the desktop, the computer shuts itself down.

## <h2 align=center>*Additional information*</h2>

In your <i>Documents/WindowsAccess</i> folder, there is a <i>Config.ini</i>, which it allows you to change specific parameters, like:

	+ How the folder should be named
	+ After how many seconds app feels obliged to check for the folder
	+ Should the app record every failed attempt into a Log folder.

Also there is a folder named <i>Logs</i> where it stores all failed attempts, date/time and on which user someone tried to log in.
When the app is runned for the first time it creates by itself all the necessary folders/files.

The app wont affect the perfomance of your computer, this will be runned once when your PC has started, and after that the app will be closed immediately.

## <h2 align=center>*Installation*</h2>

When you download the file from [WindowsAccess.exe](https://github.com/dinii0/WindowsAccess/releases/tag/windows.access), you should put this in your <i>StartUp</i> folder. And it runs by itself every time. If you want to remove it just delete it from the <i>StartUp</i> folder.
It is recommended to put this file somewhere safe, and create a <i>Shortcut</i> instead and throw it in your <i>StartUp</i> folder.

<table align="center">
  <tr>
    <td align="center">
      <h2>Issues, pull requests and repo</h2>
      <a href="https://github.com/dinii0/WindowsAccess/issues">
        <img src="https://img.shields.io/github/issues/dinii0/WindowsAccess" alt="GitHub issues">
      </a>
      <a href="https://github.com/dinii0/WindowsAccess/issues?q=is%3Aissue+is%3Aclosed">
        <img src="https://img.shields.io/github/issues-closed/dinii0/WindowsAccess" alt="GitHub issues closed">
      </a>
      <a href="https://github.com/dinii0/WindowsAccess/pulls">
        <img src="https://img.shields.io/github/issues-pr/dinii0/WindowsAccess" alt="GitHub pull requests">
      </a>
      <a href="https://github.com/dinii0/WindowsAccess/pulls?q=is%3Apr+is%3Aclosed">
        <img src="https://img.shields.io/github/issues-pr-closed/dinii0/WindowsAccess" alt="GitHub pull requests closed">
      </a>
      <br>
      <img src="https://github-readme-stats.vercel.app/api?username=dinii0&show_icons=true" alt="dinii0's GitHub Stats">
      <br>
      <h2>You can give me a star!</h2>
      <a href="https://github.com/dinii0/WindowsAccess/stargazers">
        <img src="https://i.imgur.com/FyVXkZL.png" alt="Built with Love">
      </a>
    </td>
  </tr>
</table>
