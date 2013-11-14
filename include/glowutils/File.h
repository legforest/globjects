#pragma once

#include <string>

#include <GL/glew.h>

#include <glow/StringSource.h>

#include <glowutils/glowutils.h>

namespace glow
{

class Shader;

GLOWUTILS_API Shader* createShaderFromFile(GLenum type, const std::string& filename);

/** \brief String source associated to a file.
    
    The file path of a File can be queried using filePath(); To reload the contents
    from a file, use reload().

    \see StringSource
 */
class GLOWUTILS_API File : public StringSource
{
public:
    File(const std::string & filePath);
    virtual ~File();

    virtual const std::string & string() const override;
    virtual std::string shortInfo() const override;

	const std::string & filePath() const;

    void reload();
protected:
    std::string m_filePath;
    std::string m_source;
};

} // namespace glow
